The algorithm takes an array of 𝑛 integers and a number 0≤𝑖≤𝑛−1 as inputs. It will output the 𝑖-th smallest item in the array, which is called the order-𝑖 item. Note that 𝑖 starts from 0. This means the order-0 item is the smallest one in the entire array and the order-(𝑛−1) item is the largest one. Based on the user specification, a corresponding selection algorithm will be called.

You will read the data from the standard input. (For the ease of testing, you can write each test case in a file and then use Linux file redirection function “<” to read from the file.)
The first line is an integer, which specifies the selection algorithm you should call. The integer can take two values: 0 for random selection algorithm and 1 for deterministic selection algorithm. Other values are illegal, but you can assume that the user will not input illegal values.
The second line specifies the number of integers in the input array. Let that number be 𝑛. The third line is an integer 0≤𝑖≤𝑛−1, which indicates the algorithm will output the order-𝑖 item in the array. You can assume that the user always inputs an order 𝑖 in the valid range. The following n lines list the 𝑛 integers in the array.
An example of input is
0
5
2
-1
-3
2
0
4

This example calls random selection algorithm to get the order-2 item in an array of 5 elements. That item should be 0.

The program should output:
The order-<i> item is <val>
For the above example, the output is
The order-2 item is 0