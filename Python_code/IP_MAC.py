import uuid
import socket

hostname = socket.gethostname()
IPAddr = socket.gethostbyname(hostname)
print("IP Address :" + IPAddr)
print("MAC address : ", end="")
print(':'.join(['{:02x}'.format((uuid.getnode() >> ele) & 0xff)
                for ele in range(0, 8 * 6, 8)][::-1]))