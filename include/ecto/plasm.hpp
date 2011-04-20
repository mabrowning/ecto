#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/tuple/tuple.hpp>
#include <string>
#include <map>
#include <list>
#include <ecto/tendril.hpp>

namespace ecto
{
  //forward declare module so we don't get affected by its header
  class module;
  typedef boost::shared_ptr<module> module_ptr;

  class plasm : boost::noncopyable
  {
  public:
    enum vertex_t
    {
      root, input, output, param
    };
    typedef std::map<int, boost::tuple<module_ptr, vertex_t, std::string, tendril> > vertex_map_t;
    typedef std::list<boost::tuple<size_t, size_t> > edge_list_t;

    plasm();
    void connect(boost::shared_ptr<module> from, const std::string& output, boost::shared_ptr<module> to,
                 const std::string& input);
    void mark_dirty(const boost::shared_ptr<module>& m);
    void go(const boost::shared_ptr<module>& m);
    void viz(std::ostream& out) const;
    std::string viz() const;

    vertex_map_t getVertices();
    edge_list_t getEdges();

  private:
    class impl;
    boost::shared_ptr<impl> impl_;
    friend class plasm_wrapper;
  };
}
