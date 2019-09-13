#!/usr/bin/env python3
from ctypes import *
import sys
import argparse
import base64
import time

###############################################################################
class c_msg(Structure):
    _fields_ = [("command"  , c_int),
		("size"     , c_int),
                ("deck"     , c_int * 127),
            ]

_lib_A_Game_of_Chance = CDLL('../lib/lib_A_Game_of_Chance.so')
_lib_A_Game_of_Chance.step.restype = c_msg

def cstep():
    global _lib_A_Game_of_Chance
    return _lib_A_Game_of_Chance.step()

###############################################################################
class SENDER():
    def __init__(self):
        pass

    def run(self):
        while True:
            msg = self.getTestVector()
            self.processTestVector(msg)
            time.sleep(0.1)

    def getTestVector(self):
        return cstep()

    def processTestVector(self,struc):
        deckStr = ""
        for num in struc.deck:
             deckStr += "{}".format(num)

        msg = ""
        msg += " command {}".format(struc.command)
        msg += " size {}".format(struc.size)
        msg += " deck {}".format(deckStr)
        e64 = base64.b64encode(msg.encode()).decode()
        sys.stdout.write(e64 + "\n")
        sys.stdout.flush()

###############################################################################
def main():
    parser = argparse.ArgumentParser(description="A_Game_of_Chance Relay")
    sender = SENDER()
    sender.run()

###############################################################################
if __name__ == "__main__":
    sys.exit(main())