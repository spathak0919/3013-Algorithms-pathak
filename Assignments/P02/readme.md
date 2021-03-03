## Program 2 - Processing in Linear Time



### Linear Time Lookup

This project is about loading a singly linked list with dictionary words, then timing how it takes to look them up. 
### Files

| File             | Description                                        | Location    |
| :--------------- | :------------------------------------------------- | :---------- |
| `dictionary.txt` | Words ... lots of words.                           | This Folder |
| `main.cpp`       | Example driver that reads in words and uses getch. | This Folder |
| `my_getch.cpp`   | Get character, without printing it .               | This folder |
| `timer.hpp`      | Timer helper class                                 | This Folder |
| `termcolor.hpp`  | Class to color text                                | This Folder |

#### Output Example

- User types the word `ste` 
- Below the word the number of words found and the amount of time in seconds will be printed
- Only print out the first 10 words of the matching words


```
ste

62 words found in 0.013 seconds

stead steadfast steadfastly steadfastness steadied steadier steadies steadiest steadily steadiness

```


- User types the word `steel` 

```
steel

18 words found in 0.003 seconds

steel steele steeled steelers steeles steelhead steelie steelier steelies steeliness 

```
