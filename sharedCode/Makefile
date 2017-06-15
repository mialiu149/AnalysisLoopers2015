include Makefile.arch

#
# stuff to make
#
SOURCES=$(wildcard *.cc) 
OBJECTS=$(SOURCES:.cc=.o)
LIB=libSharedCode.so

#
# how to make it 
#

$(LIB): $(OBJECTS) 
	$(LD) $(LDFLAGS) $(SOFLAGS) $(OBJECTS) $(ROOTLIBS) -lTMVA -lEG -lGenVector -lXMLIO -lMLP -lTreePlayer -o $@

%.o:	%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

#
# target to build
# likelihood id library
#

all: $(LIB) 
clean:
	rm -f *.o \
	rm -f *.d \
	rm -f *.so \
	rm -f Tools/*.o \
	rm -f Tools/*.d \
	rm -f Tools/*.so \
	rm -f Tools/MT2/*.o \
	rm -f Tools/MT2/*.d \
	rm -f Tools/MT2/*.so \
	rm -f Tools/btagsf/*.o \
	rm -f Tools/btagsf/*.d \
	rm -f Tools/btagsf/*.so
