#!/usr/bin/env python
# -*- coding: ISO-8859-1 -*-
# generated by wxGlade 0.4.1 on Sun Apr 09 21:13:20 2006

import wx
from Frame import Frame

class App(wx.App):
    def OnInit(self):
        wx.InitAllImageHandlers()
        frame = Frame(None, -1, "")
        self.SetTopWindow(frame)
        frame.Show()
        return 1

# end of class App

if __name__ == "__main__":
    app = App(0)
    app.MainLoop()
