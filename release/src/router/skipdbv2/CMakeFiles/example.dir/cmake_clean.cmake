FILE(REMOVE_RECURSE
  "CMakeFiles/example.dir/tests/example.c.o"
  "bin/example.pdb"
  "bin/example"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/example.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
