# Solution for [C. Jury Marks](https://codeforces.com/contest/831/problem/C)

### Main Observations
- We can compute all initial values from only one remembered value
- Constraints are pretty small, we can brute force

### Implementation
1. First, precompute an array <img src="svgs/ae2cddd09c035e4c939ebb892e4fcd87.svg?invert_in_darkmode" align=middle width=40.681301099999985pt height=24.65753399999998pt/> that contains the partial sum for every <img src="svgs/65ed4b231dcf18a70bae40e50d48c9c0.svg?invert_in_darkmode" align=middle width=13.340053649999989pt height=14.15524440000002pt/> up to <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/>.
2. Use an arbitrary value to create a set of all possible initial values <img src="svgs/f7a2952c2bf034e014f53210f8cec454.svg?invert_in_darkmode" align=middle width=63.14857064999999pt height=24.65753399999998pt/>, for simplicity's sake, we can use <img src="svgs/a7d0e0605a6acafe642d0b54226ac650.svg?invert_in_darkmode" align=middle width=13.60734374999999pt height=22.831056599999986pt/> as our value.
3. Now, we iterate over every element of <img src="svgs/f7a2952c2bf034e014f53210f8cec454.svg?invert_in_darkmode" align=middle width=63.14857064999999pt height=24.65753399999998pt/>, <img src="svgs/b95c2b0aab2482e5bebd25332a4bbde0.svg?invert_in_darkmode" align=middle width=12.30503669999999pt height=14.15524440000002pt/>, and add <img src="svgs/41be7709d5ee2aecb7447a7eba727f2e.svg?invert_in_darkmode" align=middle width=36.19975259999999pt height=14.15524440000002pt/>. Create another set <img src="svgs/21ae3ea9302b3bddd00aa37ccdc677a2.svg?invert_in_darkmode" align=middle width=56.86664279999999pt height=24.65753399999998pt/> from all these values.
4. Check if all <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/> remembered values are present in <img src="svgs/21ae3ea9302b3bddd00aa37ccdc677a2.svg?invert_in_darkmode" align=middle width=56.86664279999999pt height=24.65753399999998pt/> (it is sufficient to use .count(<img src="svgs/ec71f47b6aee7b3cd545386b93601915.svg?invert_in_darkmode" align=middle width=13.20877634999999pt height=22.831056599999986pt/>) since all values are distinct), it is a solution, so we can increment the number of options.

[Official Editorial](https://codeforces.com/blog/entry/53302)
