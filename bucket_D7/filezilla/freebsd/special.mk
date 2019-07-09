CC=	clang
CXX=	clang++

# clang ICEs on the test.  Just assume c++17 works
CONFIGURE_ENV+=	ax_cv_cxx_compile_cxx17__std_cpp17=yes