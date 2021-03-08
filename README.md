# Reconstruction Of Strings Problem: 
## maximal size of intersection between two _l_-balls with radius 1

The _Levenshtein distance_ between  two  words ``x`` and ``y``, denoted by ``dL(x,y)``, is the minimum number of insertions and deletions to convert ``x`` to ``y``.

The _l distance_ between two words ``x`` and ``y`` of the same length, denoted by ``dl(x,y)``, is one half the Levenshtein distance, i.e., ``dl(x,y)=dL(x,y)/2``.

The radius-_r_ _l_-ball of a length-_n_ word ``x`` is the set ``Bl(x;r){ y|  y is binary string of length n and dl(x,y)<=r}``.

with a given string length-_n_, calculating the maximal size of intersection between two _l_-balls of two different string with radius 1, i.e. ``x≠y`` is ``max|Bl(x;1)∩Bl(y;1)|``, is ``x`` and ``y`` which satisfy the condition``dl(x,y)=1``.

### Prerequisites
Any C++11 environment.

### Installing
```
go get github.com/Aleen98/Reconstruction-Of-Strings-Problem 
```

## Running the tests 
The test will be run using C++11, that is installed on setup.
