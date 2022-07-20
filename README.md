Name: Maciuca Alexandru Petru
Group: 324CA
Course: PA
Title: PA TEMA-1

April 2022

# About the code
    The homework is divided into four distinct problems, each of them being
    based on different concepts studied during the semester such as:
    "Divide et Impera", "Greedy", "Dynamic Programming" and "Backtracking".

## Structure
    The archive contains four .cpp-implemented sources in which each task is
    solved one at a time.
    (eg: walsh.cpp, statistics.cpp, prinel.cpp, crypto.cpp)

* Walsh.cpp
    For this task, I have used "Divide et Impera" in order to split the matrix
    into four similar ones.
    The idea is to avoid generating a whole entire dial, and instead I went down
    in recursion, reaching a general case that calculates a single element.
    The solution is similar to a problem presented during the semester called
    "Z-Parcurgere".

* Statistics.cpp
    For this task, I have used "Greedy" in order to obtain the final result.
    The idea is to generate a result for every letter of the alphabet and then
    choose the best.(max result)
    In order to implement the "Greedy" algorithm, the array of strings has to 
    be sorted in a way that helps us choose the most suitable words for our
    task
    Defining the gain for letter 'a' in a string:
    def:  Gain = "The number of appearances of letter 'a' in this specific
    string" - "The rest of the letters from the string that are different
    from 'a'"
    For better complexity I have blindly choosen every word with a positive
    or equal with zero gain and sorted the rest in descending order.

* Prinel.cpp
    For this task, I have used "Dynamic Programming" in order to generate the
    result.
    The idea is to divide the problem into two separte ones, firstly I have to
    generate a target for a specific number 'X' using "Dynamic Programming" and
    secondly the problem is reduced to "RUCSAC" that has been presented during
    the semester.
    In order to avoid generating an absurd amount of numbers, I have decided 
    to store the results in an array called "targets" in order not to
    recalculate those over and over again. 
    I search for the biggest number in the array and then generate targets for
    all the numbers lower than it so next time I need to use a target, the
    search could be done in O(1) and then use this array
    similar as the "weights" array presented in "RUCSAC".

* Crypto.cpp
    For this task, I have used "Dynamic Programming" in order to generate the
    result.
    The idea is to use to create a frequency array for every possible substring
    from the one that I am searching.
    eg: searching "xyz" in "x?y?z"
                                   0  1    2    3
    frequency array should hold : [] [x] [xy] [xyz]
    freq[0] = how many [] subtrings can be created using a specific letter
    freq[1] = how many [x] subtrings can be created using a specific letter
    freq[2] = how many [xy] subtrings can be created using a specific letter
    and so on...

    Then I create an Auxiliary array similar to this one and for every step
    of the "Dynamic Programming" I use freq_aux that is always one step behind
    so I have access to elements from the past.

#### Difficulties
    I had a lot of trouble upgrading my solutions so they match the given
    time restrictions.

##### Bibliography
    "PA - Tema 1.pdf"
    "DI" -> https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-01
    "Greedy" -> https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-02
    "DP" -> https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03
         -> https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-04


