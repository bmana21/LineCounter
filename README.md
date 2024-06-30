# Line Counter

C++ program to analyze application source code data.

This counts number of files and lines for desired languages.

## How to compile

Navigate to the project directory and compile with the following command:

````
$ g++ --std=c++20 *.cpp *.h -o LineCounter
````
Now use can use generated LineCounter(.exe) binary.

## Usage

````
$ ./LineCounter.exe <folder location> <language #1> <language #2> <language #3> ...
````

## Example

````
$ .\LineCounter.exe "path\to\project\source" java sql xml css
Listing source code data

File extension: .css
Number of files: 9
Number of lines: 1158

File extension: .java
Number of files: 66
Number of lines: 4673

File extension: .sql
Number of files: 2
Number of lines: 91

File extension: .xml
Number of files: 1
Number of lines: 120

Total number of files: 78
Total number of lines: 6042
````

## Contribution

You can contribute to this project,
use PRs.