file(REMOVE_RECURSE
  "CMakeFiles/GenerateParser"
  "../../demo/generated/Python3Lexer.cpp"
  "../../demo/generated/Python3Parser.cpp"
  "../../demo/generated/Python3BaseListener.cpp"
  "../../demo/generated/Python3BaseVisitor.cpp"
  "../../demo/generated/Python3Listener.cpp"
  "../../demo/generated/Python3Visitor.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GenerateParser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
