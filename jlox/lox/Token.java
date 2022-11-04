package jlox.lox;

public class Token {
    final TokenType type;
    final String lexeme;
    final Object literal;
    final int line;
    // Constructor
    Token(TokenType inputType, String inputLexeme, Object inputLiteral, int inputLine) {
        type = inputType;
        lexeme = inputLexeme;
        literal = inputLiteral;
        line = inputLine;
    }

    public String toString() {
        return type + " " + lexeme + " " + literal;
    }
}
