# Encoder
In this project I have implemented an encoder, channel and decoder based on an algorithm. Functionally the user should be able to enter a text of characters in the input
file and run the encoder with 2 command line arguements - the first arguement is the name of input file (inputData) that we're reading and the second arguement is the
output file (encodedData) that we're writing to. The channel takes encodedData as input and writes onto transmittedData as output, again, using command line arguements. 
The idea is to corrupt the data in the transmission channel by flipping 1 bit in each character. The decoder takes corrupted data file transmittedData as input and 
outputs decodedData. The decodedData file should be identical to the inputData file. We are using even parity an encoding algorithm. Parity bit p0 is calculated based
on data bits d0, d1 and d2. Parity bit p1 is calculated based on data bits d0, d1 and d3. Parity bit p2 is calculated based on data bits d1, d2 and d3. The most 
significant bit is always 0.

For a simpler explanation with graphs and charts, you can check out the pdf file in this folder.
