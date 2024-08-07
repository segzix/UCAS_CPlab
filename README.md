# CACT compiler

## build

### using antlr4 to generate files from grammar file

```bash
java -jar ../deps/antlr-4.13.1-complete.jar -Dlanguage=Cpp CACT.g4 -visitor -no-listener
```

### compile the cmake project

```bash
mkdir -p build
cd build
cmake ..
make -j
./compiler ../test/samples_lex_and_syntax/00_true_main.cact
```

## 组员

<!-- readme: collaborators,contributors -start -->
<!-- readme: collaborators,contributors -end -->
