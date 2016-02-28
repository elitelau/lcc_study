// warn & error info if ${LCC_LIB_PATH}/cpp points to system installed cpp, rather than 
// compiling from lcc package
//
// <command line>:3:1: warning: "__STDC__" redefined
// a.c:2: missing "
// a.c:3: syntax error; found `}' expecting `;'
// a.c:3: skipping `}'
// a.c:3: warning: missing return value
// a.c:3: syntax error; found `end of input' expecting `}'

int main() {
  const char* str = "a
}
