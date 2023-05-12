# Detect language

This program detects the language of a given document using the Levenshtein Distance algorithm. It is implemented in C for performance purposes and can be further optimized using GCC macros and shortcuts. The program excludes non-ASCII characters for now, which affects its precision.

## Usage

To run the program, simply run the executable and provide the path to the file you want to analyze. For a more verbose output, use the `make debug` or `make hard_d` commands.

## Implementation Details

The program generates a frequency table for each language it supports, based on the relative frequencies of letters in that language. Then, it calculates the Levenshtein Distance between the document and the frequency tables, using the lowest distance as the language detection result.

Unit tests were conducted on the Levenshtein Distance algorithm to ensure its accuracy and can be generated with the `make test` command.

## Resources

- Letter frequency: https://en.wikipedia.org/wiki/Letter_frequency#Relative_frequencies_of_letters_in_other_languages
- Levenshtein Distance: https://en.wikipedia.org/wiki/Levenshtein_distance
- Choice of algorithm: https://stackabuse.com/levenshtein-distance-and-text-similarity-in-python/```
