#!/usr/bin/env python3
import sys
from sys import stdin
import argparse
import base64

###############################################################################
class RELAY():
    def __init__(self):
        pass

    def run(self):
        while True:
            msg = self.getTestVector()
            self.processTestVector(msg)

    def getTestVector(self):
        payload = stdin.readline()
        un64 = base64.b64decode(payload.encode()).decode()
        pairlist = un64.split()
        assert(0 == (len(pairlist) % 2))
        pairs = [pairlist[i:i+2] for i in range(0,len(pairlist),2)]
        alist = { key: value for (key,value) in pairs}
        return alist

    def processTestVector(self,msg):
        main = int(msg["main"]) % 5 + 1
        movID = int(msg["movID"]) % 100 + 1
        flag = int(msg["flag"]) % 2
        passLength = int(msg["passLength"]) % 130 + 1
        passStr = msg["passStr"]
        admin = int(msg["admin"]) % 5 + 1
        titleLength = int(msg["titleLength"]) % 100 + 1
        title = msg["title"]
        descLength = int(msg["descLength"]) % 100 + 1
        desc = msg["desc"]
        year = int(msg["year"]) % 216 + 1800
        score = int(msg["score"]) % 100 + 1
        genre = int(msg["genre"]) % 5 + 1
        rating = int(msg["rating"]) % 5 + 1

        msg = ""
        if (main == 1): #list
            msg = "{main}".format(main = main)
            sys.stdout.write(msg)
            sys.stdout.flush()
        elif (main == 2 || main == 3): #rent (2) or return (3) have the same msg formats
            msg = "{main}".format(main = main)
            sys.stdout.write(msg)
            sys.stdout.flush()
            msg = "{movID}".format(movID = movID)
            sys.stdout.write(msg)
            sys.stdout.flush()
        elif (main == 4): #login
            msg = "{main}".format(main = main)
            sys.stdout.write(msg)
            sys.stdout.flush()
            if (flag == 0): #login with "admin"
                msg = "{username}".format(username = "admin")
                sys.stdout.write(msg)
                sys.stdout.flush
                msg = "{password}".format(password = passStr[:passLength])
                sys.stdout.write(msg)
                sys.stdout.flush

                if (passLength > 64): #Vulnerability exploit, successful login
                    if (admin == 1 or admin == 3): #add (1) or update (3) have almost identical msg formats
                        msg = "{admin}".format(admin = admin)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        if (admin == 3): #Give movie ID
                            msg = "{movID}".format(movID = movID)
                            sys.stdout.write(msg)
                            sys.stdout.flush
                        msg = "{title}".format(title = title[:titleLength])
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{desc}".format(desc = desc[:descLength])
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{year}".format(year = year)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{score}".format(score = score)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{genre}".format(genre = genre)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{rating}".format(rating = rating)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{logout}".format(logout = 4) #Ensure each test ends back on the main screen
                        sys.stdout.write(msg)
                        sys.stdout.flush
                    elif (admin == 2): #remove
                        msg = "{admin}".format(admin = admin)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{movID}".format(movID = movID)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                        msg = "{logout}".format(logout = 4)
                        sys.stdout.write(msg)
                        sys.stdout.flush
                    else: #logout (4) and exit (5) have the same msg format
                        msg = "{admin}".format(admin = admin)
                        sys.stdout.write(msg)
                        sys.stdout.flush
            else: #login with random username
                msg = "{username}".format(username = passStr[:passLength])
                sys.stdout.write(msg)
                sys.stdout.flush
        else: #exit
            msg = "{main}".format(main = main)
            sys.stdout.write(msg)
            sys.stdout.flush

###############################################################################
def main():
    parser = argparse.ArgumentParser(description="Movie_Rental_Service Relay")
    relay = RELAY()
    relay.run()

###############################################################################
if __name__ == "__main__":
    sys.exit(main())