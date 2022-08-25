# Detect language
I made a program who can detect in which language a given document is written. It's precision can greatly be improved since I excluded non-ascii characters, mainly for performance purposes.

Language & algorithm choice
--------------------
I chose to code this program in C since it is a very fast language, but you can also focus on micro-optimisations
and use GCC macros and shortcuts to make your program as fast and as performent as possible.
For the algorithm, I implemented the Levenshtein Distance since it is used to compute changes or edits between two strings,
which is really useful for seeking text similarity.

Verbose output
--------------------
To have a more verbose output you can type "make debug" or "make hard_d". It will prompt all operations
the program is doing to come to the final result.

Unit tests
--------------------
I did some unit testing on the Levenshtein Distance algorithm to be sure everything is working as intended.
The unit tests can be generated with "make test"

Ressources
-----------------------------------
-   Letter frequency: https://en.wikipedia.org/wiki/Letter_frequency#Relative_frequencies_of_letters_in_other_languages
-   Levenshtein Distance: https://en.wikipedia.org/wiki/Levenshtein_distance
-   Choice of algorithm: https://stackabuse.com/levenshtein-distance-and-text-similarity-in-python/
