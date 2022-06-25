833. Find And Replace in String
## Describe
You are given a 0-indexed string s that you must perform k replacement operations on. The replacement operations are given as three 0-indexed parallel arrays, indices, sources, and targets, all of length k.

### Example
  ```
  Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
  Output: "eeebffff"
  Explanation:
  "a" occurs at index 0 in s, so we replace it with "eee".
  "cd" occurs at index 2 in s, so we replace it with "ffff".
  ```
## Idea
* input indices not necessarily in order, so using pair to maintain indices sorting relation.
* if sub_str == source_str, ans_str = ans_str + target_str, else ans_str = ans_str + str
