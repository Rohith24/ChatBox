CHAT BOX PROGRAM

Problem Statement: 

Write a chat box command line program using files  (client server program)  which uses files as medium for their communication. 
[If you find anything wrong mentioned here either Wrong tasks listed etc, Do let Abhijith know ] 


Task 1:

	Here chatbox contains only two members(say client and server) where one member speaks and other listens at a given instance. In this task you can use only two files.

Create two VS projects. One for client and other for server.
Use two files “client.bin” and “server.bin” where client uses client.bin file for reception and server.bin to send message to server. Similarly server uses server.bin to receive messages from client.bin to send messages to client. 
Client opens client.bin in read mode and server.bin in write mode. Similarly server opens client.bin in write mode and server.bin in read mode.
Initially server listens and client speaks.



Task 2:

	In this task, client and server communicates from only  one file. Client and server opens that file in “r+” or “rb+” mode for communication. 


Task 3:
	
	Here, At a given instance, both client and server should be in listening and speaking states simultaneously  i.e, if client messages server once, then after client must be able to speak again(send another message again even though server didn't reply) or listen to server. Similarly server too. Use threading concepts to listen and speak simultaneously.

Stretch Goal :
Task 4:

	Perform above task with multiple users (a kind of group chat).

