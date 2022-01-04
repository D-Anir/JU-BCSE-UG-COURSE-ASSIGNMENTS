import socket

HOST = '127.0.0.1'  # The server's hostname or IP address
DHCPport = 65100        # The port used by the server

name = input("Enter name of the client: ")

# Create a UDP Socket
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Client Started...")

address = (HOST, DHCPport)

print("Requesting for temporary IP from DHCP Server...")
client.sendto(str.encode("request"), address)
ip, server = client.recvfrom(1024)
if(ip.decode() == "-1"):
    print("\nNo IP Address available from Server, maximum clients connected..\n")
else:
    print("Temporary IP Allocated! [" + ip.decode() + "]")
    while True:
        print("Press q to quit, anything else to stay online.")
        choice = input()
        if choice == "q" or choice == "Q":
            break
    print("Terminating...\n")
    client.sendto(ip, address)
