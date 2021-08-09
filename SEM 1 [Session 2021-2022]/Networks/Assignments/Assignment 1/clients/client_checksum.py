import sys, pickle, socket

sys.path.append("..")

from receiver import *

SCHEME_NAME = 'CHECKSUM'

s = socket.socket()

port = 12345

s.connect(('127.0.0.1', port))

s.send(pickle.dumps(SCHEME_NAME))

data = []
while True:
    packet = s.recv(4096)
    if not packet: break
    data.append(packet)
data_value = pickle.loads(b"".join(data))

if type(data_value) is str:
    print("Invalid Connection!")

else:
    r = Receiver(data_value)
    r.check_error(SCHEME_NAME)
    r.display_packets(SCHEME_NAME)

s.close()
