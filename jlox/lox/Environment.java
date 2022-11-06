package jlox.lox;

import java.util.HashMap;
import java.util.Map;

public class Environment {
    final Environment enclosing;
    private final Map<String, Object> values = new HashMap<>(); // store the bindings

    Environment() { // for global scope
        enclosing = null;
    }

    Environment(Environment enclosing) { // for local scope
        this.enclosing = enclosing;
    }

    Object get(Token name) {
        if (values.containsKey(name.lexeme)) {
            return values.get(name.lexeme);
        }
        // if the variable is not found in the current scope, look in the enclosing scope
        if (enclosing != null) return enclosing.get(name);
        throw new RuntimeError(name, "Undefined variable '" + name.lexeme + "'.");
    }

    void assign(Token name, Object value) {
        if (values.containsKey(name.lexeme)) {
            values.put(name.lexeme, value);
            return;
        }
        // if the variable is not found in the current scope, look in the enclosing scope
        if (enclosing != null) {
            enclosing.assign(name, value);
            return;
        }
        throw new RuntimeError(name, "Undefined variable '" + name.lexeme + "'.");
    }

    void define(String name, Object value) { 
        // allow redefinition of variables for now
        values.put(name, value);
    }

    Object getAt(int distance, String name) {
        return ancestor(distance).values.get(name);
    }

    void assignAt(int distance, Token name, Object value) {
        ancestor(distance).values.put(name.lexeme, value);
    }

    Environment ancestor(int distance) {
        Environment environment = this;
        for (int i = 0; i < distance; i++) {
            environment = environment.enclosing;
        }
        return environment;
    }
}
