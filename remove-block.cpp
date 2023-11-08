#include <string>
#include <stdexcept>
#include <iostream>

enum class State {
    Code,
    Comment,
    MaybeEnterComment,
    MaybeExitComment
};

std::string removeBlockComments(const std::string& input) {
    std::string output;
    State state = State::Code;

    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];

        switch (state) {
            case State::Code:
                if (ch == '/' && i + 1 < input.size() && input[i + 1] == '*') {
                    state = State::MaybeEnterComment;
                    i++; // Skip the '*' as it's part of the comment start
                } else {
                    output += ch;
                }
                break;
            
            case State::MaybeEnterComment:
                if (ch == '*') {
                    state = State::Comment;
                } else {
                    // It wasn't a comment after all
                    output += '/'; // Append the previously skipped '/'
                    output += ch;  // Append the current character
                    state = State::Code;
                }
                break;

            case State::Comment:
                if (ch == '*' && i + 1 < input.size()) {
                    state = State::MaybeExitComment;
                } else if (ch == '/' && i + 1 < input.size() && input[i + 1] == '*') {
                    // Nested comment detected
                    throw std::runtime_error("Error: Nested comments are not allowed.");
                }
                break;

            case State::MaybeExitComment:
                if (ch == '/') {
                    state = State::Code;
                } else if (ch != '*') {
                    // False alarm, still in comment
                    state = State::Comment;
                }
                // If the character is '*', then we stay in MaybeExitComment state
                break;
        }
    }

    if (state == State::Comment || state == State::MaybeExitComment) {
        throw std::runtime_error("Error: Unterminated comment block.");
    }

    return output;
}

int main() {
    std::string code = "int main() {/* This is a comment */ return 0;}";
    try {
        std::string cleanCode = removeBlockComments(code);
        std::cout << cleanCode << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
