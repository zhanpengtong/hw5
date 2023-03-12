# Sort Analysis Data

## Results Table
Make sure to go out to at least 100,000 (more are welcome), and you have 10 different values (more welcome). You are welcome to go farther, but given 100,000 can take about 20 seconds using a selection sort on a fast desktop computer, and 200,000 took 77 seconds, you start having to wait much longer the more 0s you add. However, to build a clearer line, you will want more data points, and you will find merge and quick are able to handle higher numbers easier (but at a cost you will explore below). 

You are free to write a script to run the program and build your table (then copy that table built into the markdown). If you do that, please include the script into the repo.  Note: merge sort is going to be completed in the workshop for Module 06. You can start on it now, but welcome to wait.

### Table

![Screenshot 2023-03-11 at 8 48 38 PM](https://user-images.githubusercontent.com/113164203/224519818-36bd95db-c881-49c8-961a-2cd7e1fa771e.png)




## BigO Analysis  / Questions

### 1. Build a line chart
Build a line chart using your favorite program. Your X axis will be N increasing, and your Y access will be the numbers for each type of sort. This will create something similar to the graph in the instructions, though it won't be as smooth.

Include the image in your markdown. As a reminder, you save the image in your repo, and use [image markdown].

![Running Time Table](https://user-images.githubusercontent.com/113164203/224525235-a041d180-982d-49bd-9fdc-00577d412540.png)


### 2. Convinced?
Given the direction of the line chart, are you "convinced" of the complexity of each of the sorts? Why or why not?

Yes, that is a reasonable interpretation of the line chart. The direction of the lines does seem to align with the expected time complexity of each sorting algorithm, as defined by Big-O notation. Merge Sort and Quick Sort are expected to have a time complexity of O(nlogn), while Bubble Sort and Selection Sort have a time complexity of O(n^2).


### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 

![best, average, worst case](https://user-images.githubusercontent.com/113164203/224526879-32bcbe2f-b98f-489b-9899-d23e0af47aa2.png)

Interview Kickstart. (n.d.). Time Complexities of All Sorting Algorithms. Retrieved from https://www.interviewkickstart.com/learn/time-complexities-of-all-sorting-algorithms

#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts

1. Bubble Sort: The worst case scenario for Bubble Sort is when the input array is in reverse order. For example, the array [5, 4, 3, 2, 1] is a worst case scenario for Bubble Sort.
2. Selection Sort: The worst case scenario for Selection Sort is also when the input array is in reverse order. For example, the array [5, 4, 3, 2, 1] is a worst case scenario for Selection Sort.
3. Insertion Sort: The worst case scenario for Insertion Sort is when the input array is in reverse order and each element must be moved all the way to the beginning of the array. For example, the array [5, 4, 3, 2, 1] is a worst case scenario for Insertion Sort.
4. Merge Sort: The worst case scenario for Merge Sort is when the input array is already sorted in reverse order, which causes the merge step to perform the maximum number of comparisons. For example, the array [5, 4, 3, 2, 1] is a worst case scenario for Merge Sort.

#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 

1. Bubble Sort: The best case scenario for Bubble Sort is when the input array is already sorted. For example, the array [1, 2, 3, 4, 5] is a best case scenario for Bubble Sort.
2. Selection Sort: The best case scenario for Selection Sort is also when the input array is already sorted. For example, the array [1, 2, 3, 4, 5] is a best case scenario for Selection Sort.
3. Insertion Sort: The best case scenario for Insertion Sort is when the input array is already sorted. For example, the array [1, 2, 3, 4, 5] is a best case scenario for Insertion Sort.
4. Merge Sort: The best case scenario for Merge Sort is also when the input array is already sorted. For example, the array [1, 2, 3, 4, 5] is a best case scenario for Merge Sort.

#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 

(Quick sort = Merge Sort) > (Bubble = Selection = Insertion)
        O(n)                            O(1)

### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

$n^2$  
$n!$  
$n\log_2n$  
$5n^2+5n$  
$10000$  
$3n$    
$100$  
$2^n$  
$100n$  
$2^{(n-1)}$
#### Categories

*constant growth
        $100$ |
        $10000$

*linear growth
        $3n$  |
        $100n$

*logarithmic growth
        $n\log_2n$

*quadratic growth
        $5n^2+5n$  |
        $n^2$

*exponential growth
        $2^{n-1}$

*factorial and exponential growth
        $n!$  |
        $2^n$


### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    |  Cubic |
| $O(1)$      | Constant  |
| $O(n)$      | Linear  |
| $O(\log_2n)$ | Logarithmic  |
| $O(n^2)$    | Quadratic  |
| $O(n!)$     | Factorial  |
| $O(2^n)$    | Exponential  |



### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  

Stability in sorting refers to the preservation of the relative order of equal elements. A stable sorting algorithm maintains the original order of equal elements, while an unstable algorithm may change their order. The stable sorting algorithm preserves the original order of two numbers to be sorted when they are equal. Unstable sorting algorithm When two numbers to be sorted are equal, their order may change in the sorted output array.

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 

For example, I have a report card that records students' names and grades, and I need to sort the grades first by subject (e.g. math, science, English) and then by the student's name in each subject. To ensure that students' grades match their names, this requires a robust sorting algorithm, as it preserves the order of students' grades in each subject. If an unstable sorting algorithm is used, it may reorder the grades for each subject, leading to incorrect results.

### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles. 

I will first divide the 250 coins into two piles of 125 coins each. Re-divide the heavy coins into two piles of 62 and one extra coin. If the weights of the two piles are equal, then the extra coin is what we are looking for. If not, then re-divide the heavy 62 coins into two piles of 31 coins each. Then take out the heavy pile of coins and re-divide into two piles of coins, each pile has 15 coins, and there is an extra coin. If the weights of the two piles are equal, then the extra coin is what we are looking for. If not then re-divide the heavy 15 coins into two piles of 7 coins and one extra coin. If the weights of the two piles are equal, then the extra coin is what we are looking for. If not then re-divide the heavy 7 coins into two piles of 3 coins and one extra coin. If the weights of the two piles are equal, then the extra coin is what we are looking for. If not then re-divide the heavy 3 coins into two piles of 1 coin and an extra coin. If the weights of the two piles are equal, then the extra coin is what we are looking for. If it's not that heavy that coin is what we're looking for.

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.

1. Divide the 250 coins into two groups of approximately equal size, A and B.
2. Weigh group A against group B on the balance scale.
3. If the two groups weigh the same, then the rare coin must be in the remaining 125 coins. Go back to step 1 and repeat the     process with the remaining coins.
4. If group A is heavier than group B, then the rare coin must be in group A. Go back to step 1 and repeat the process with group A.
5. If group B is heavier than group A, then the rare coin must be in group B. Go back to step 1 and repeat the process with group B.


#### 7.2 Time Complexity
What is the average time complexity of your algorithm? 

The time complexity of the algorithm is O(log2 n), where n is the number of coins. This is because the algorithm repeatedly divides the pile of coins into halves and only weighs one of the halves at each iteration. This is a binary search algorithm, and the time complexity of a binary search is logarithmic.


<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images
