use strict;
use warnings;

# Example list of file names
my @file_names = (
    'foo_str1_str2_2000_watt_str3_str4.txt',
    'bar_str1_150_watt_str2.txt',
    'anotherfile_300_watt_str.txt',
    # add more file names as needed
);

foreach my $file_name (@file_names) {
    # Match a substring that starts with an underscore, followed by
    # one or more digits (\d+),
    # followed by "_watt". The parentheses capture the matched part.
    if ($file_name =~ /(_\d+_watt)/) {
        # $1 contains the first matched part from the regex
        my $matched_substring = $1;
        print "Found substring: $matched_substring\n";
    } else {
        print "No matching substring found in $file_name\n";
    }
}


# Example list of file names
@file_names = (
    'foo_str1_str2_2000_watt_str3_str4.txt',
    'bar_str1_150_watt_str2.txt',
    'anotherfile_300_watt_str.txt',
    # add more file names as needed
);

foreach my $file_name (@file_names) {
    # Match a substring that starts with an underscore,
    # followed by one or more characters (.+),
    # followed by "_watt". The parentheses capture the matched part.
    if ($file_name =~ /(_.+_watt)/) {
        # $1 contains the first matched part from the regex
        my $matched_substring = $1;
        print "Found substring: $matched_substring\n";
    } else {
        print "No matching substring found in $file_name\n";
    }
}


# Example list of file names
@file_names = (
    'foo_str1_str2_2000_watt_str3_str4.txt',
    'bar_str1_150_watt_str2.txt',
    'anotherfile_300_watt_str.txt',
    # Add more file names as needed
);

foreach my $file_name (@file_names) {
    # Match a substring that starts with an underscore,
    # followed by one or more characters,
    # followed by "_watt" without capturing
    # true/false
    if ($file_name =~ /_.+_watt/) {
        print "Matching substring found in $file_name\n";
    } else {
        print "No matching substring found in $file_name\n";
    }
}


# Example list of file names
my @file_names = (
    'foo_str1_str2_2000_watt_str3_str4.txt',
    'bar_str1_150_watt_str2.txt',
    'anotherfile_300_watt_str.txt',
    # Add more file names as needed
);

foreach my $file_name (@file_names) {
    # Match a substring that starts with an underscore,
    # followed by one or more characters,
    # followed by "_watt" without capturing
    if ($file_name =~ /_.+_watt/) {
        print "Matching substring found in $file_name\n";
    } else {
        print "No matching substring found in $file_name\n";
    }
}

my $string = "start_123_watt_end_456_watt_more";

if ($string =~ /_(\d+)_watt.*?_(\d+)_watt/) {
    print "First match: $1, Second match: $2\n";
}

$string = "start_123_watt_end_456_watt_more";

while ($string =~ /_(\d+)_watt/g) {
    print "Found match: $1\n";
}

# The .*? in a regular expression is a combination of two
# elements: .* and ?, and it's used to perform a non-greedy
# or lazy match of any sequence of characters.

#   . (dot) matches any single character, except newline
# characters by default.
#   * (asterisk) is a quantifier that matches zero or more
# occurrences of the preceding element (in this case, any
# character due to the dot).
#   ? immediately after * makes the match lazy (non-greedy),
# meaning it will match as few characters as possible while
# still allowing the overall regular expression to match.

# Greedy vs. Lazy Matching

#   Greedy matching (with .*) tries to match as much text as possible.
# Given the string abc123def, the pattern .*def would match the
# entire string because .* consumes as much as it can, and still
# allows the pattern to match.
#   Lazy matching (with .*?), on the other hand, matches as little
# text as possible. In the same string abc123def, the pattern .*?def
# would match minimally until reaching the first occurrence of def.
