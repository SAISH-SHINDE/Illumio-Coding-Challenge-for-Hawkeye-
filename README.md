# Illumio-Coding-Challenge-for-Hawkeye-

Testing the Code:

For testing the code I ran various tests apart from the one mentioned. I tested the flow table address to check if they are starting with the "asterisk" symbol and if "asterisk" symbol appears in the address, it throws the error message. I have also tested the code for the range of port addresses given in the NAT file.

Coding, Design and Algorithm details:

For the given coding assignment I took into account various string manipulation techniques along with space and time complexity. I broke down the NAT addresses and Flow addresses into first IP and first port no. using the string manipulation techniques putting them later into a map as clearly seen in the code to find a match between the given Flow address and NAT address. MAP helped to maintain the space complexity to be O(1). In the special case of "*" symbol occurring in the NAT address, the space complexity of the operation remained O(1) while it suffers in time complexity in searching the corresponding port no. or IP address. Also, MAP helped to link the 2nd IP and port no. when the match occurred to be written into the output file with runtime complexity of O(1) due to direct linking.

Optimizations and Refinements If I had more time:

If I had more time for optimizing the solution I would have tried to use mapped binary tree in order to reduce the searching operation to the logarithmic complexity and also to store large datasets. Implementing this data structure would lead better time complexity.

My Interest:

I am interested to be part of Virtual Enhancement Node Team serving as a major input to the Policy Compute Engine, the core part of Illumio. :-)
