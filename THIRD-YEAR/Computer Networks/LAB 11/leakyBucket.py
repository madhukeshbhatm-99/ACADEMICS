BUCKET_SIZE = int(input("Enter the maximum bucket size: "))

def leaky_bucket(output_rate, packet_size):
    if packet_size <= output_rate:
        print("Bucket Output is Successful\nLast {}bytes was sent".format(packet_size))
    elif packet_size <= BUCKET_SIZE:
        print("Bucket Output is Successful")
        print("Last {}bytes was sent".format(output_rate))
        rem_size = packet_size - output_rate
        while rem_size > 0:
            if rem_size >= output_rate:
                print("Last {}bytes was sent".format(output_rate))
            else:
                print("Last {}bytes was sent".format(rem_size))
            rem_size -= output_rate
    else:
        print("Oops, bucket OVERFLOW!!")

output_rate = int(input("Enter bucket output rate: "))
packets = int(input("Enter the number of packets: "))
for packet in range(packets):
    print()
    packet_size = int(input("Packet {} Size: ".format(packet)))
    leaky_bucket(output_rate, packet_size)