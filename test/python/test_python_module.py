#!/usr/bin/env python
import ecto

class MyModule(ecto.module):
    def __init__(self, *args, **kwargs):
        ecto.module.__init__(self, **kwargs)
        
    @staticmethod
    def Params(params):
        print "setting params!"
        params.declare("text", "a param.","hello there")
        print "params=", params

    def Config(self):
        self.text = self.params.text
        self.inputs.declare("input","aye", 2)
        self.outputs.declare("out", "i'll give you this", "hello")
        
    def Process(self):
        c = int(self.inputs.input)
        self.outputs.out = c*self.text
        print MyModule.__name__

def test_python_module():
    # t = ecto.tendrils()
    # print "t=", t
    # print MyModule.Params
    # MyModule.Params(t)
    # print t
    print MyModule
    mod = MyModule(text="spam")
    mod.Process()

if __name__ == '__main__':
    test_python_module()
