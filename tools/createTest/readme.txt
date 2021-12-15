*** UPD 14/12/2019
	RandPair/RandArrayPair : Add first is less than second
	Example RandPair(1,100)		// 95 23
		RandPair(1,100,1)	// 23 95
		RandArrayPair like RandPair

- Open folder "createTest".
- Put "*.cpp" or "*.exe" file into folder "createTest" (if using exe, add "//" before "#define USING_CPP").
- Open "createTest.cpp" as CodeBlocks or some IDE like that.
- Write your code in create_inp(), run it and you have depression :)
- Note: Don't edit main();
- Your test will be locate at folder "_Tasks".

Function:
	RandReal: 	random real number
	RandLLong: 	random long long(-2^63, 2^63-1) integer
	RandInt: 	random int(-2^31, 2^31-1) integer
	RandArray: 	random an integer array 
	RandPair	random a pair
	RandArrayPair	random an array pair
	RandMatrix:	random a matrix/2d array
	RandString: 	random string
	RandChar 	random a char
	RandTree:	random a tree
	RandMultigraph: random a multigraph
	RandGraph:	random a graph

Example:
	RandReal(-0.3231231, 0.99923);	//0.56763
	RandLLong: same RandInt;				
	RandInt(3231, 3812739);		//93843

	RandArray(size, from, to);	size:9_from:1_to:100 	//32 5 2 1 9 99 49 60 15

	RandPair(1, 100)		// 32 59
	RandArrayPair(5, 1, 100)
	// 21 34
	// 10 55
	// 94 32
	// 31 22
	// 44 78
	RandMatrix(row, column, from, to); 
		//row:3_column:4_from:1_to:10
		//10 1 2 9
		// 8 7 4 5
		// 1 2 6 3

	RandString(len, string);	len:4_string:"ABCXYZ"	//ACYZ
	RandString(len, charleft, charright);	
		len:9_charleft:'a'_charright:'z'		//azieecmwp

	RandChar: like RandString but return a char

	RandTree(node);			
	RandMultigraph(node, edge);
	RandGraph(node, edge);

***RandArray return vector <int>
***RandMatrix return vector <vector <int>>
***RandTree/Multigraph/Graph return vector <pair <int, int>>

