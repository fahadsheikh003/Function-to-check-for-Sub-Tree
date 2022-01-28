# Function-to-check-for-Sub-Tree
Function to check if one Tree is a Subtree of other one or not

# Problem:
Tl and T2 are two binary trees, with Tl bigger than T2. Create a function to determine if T2 is a subtree of Tl. A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical. Both trees are passed as an argument to the function. The function will return true is T2 is a subtree of T1, otherwise it will return false.

# Explanation of Implementation:
In this problem, I have applied the divide & conquer technique. Firstly, I made a recursive function named “datacomparison” to check if two Trees are similar or not. Then I checked either if both are same or becomes same (e.g., isSubTree(root, root->left)) or if we reached end of first tree or if second Tree is initially NULL as empty set is a subset of all sets or compared both trees and returned from function accordingly. If reach the end of function then we will repeat the same process above for left subtree of T1, if left subtree is similar to T2 which results in returning true, if not we will repeat the process for right subtree of T1 and will continue to do so until we found our subtree or when T1 reached the bottom and no similar tree was found in T1.
