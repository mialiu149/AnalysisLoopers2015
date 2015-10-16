# simple make file to compile the Z_looper

# low level stuff that independent of this project
# ----------------------------------------------------------------------- #

# include ROOT friendly c++ variables
include Makefile.arch

# conveniance command to make shared libs
SHAREDLIB.cc = $(CXX) $(ROOTLIBS) $(CPPFLAGS) $(LDFLAGS) $(SOFLAGS) $(TARGET_ARCH) -fPIC -o

# ROOT is missing the GenVector in its default setup 
LDFLAGS += -lGenVector -lEG -lTMVA -lMinuit -lMLP -lXMLIO -lTreePlayer -lMathMore

# CMS2 specific includes 
# ----------------------------------------------------------------------- #


# cms2_tools  := ../Tools
# CPPFLAGS  += -I$(cms2_tools) 
# LDFLAGS   += -L$(cms2_tools) 

# add looperTools support
cwelke_tools  := ../looperTools
CPPFLAGS  += -I$(cwelke_tools) 
LDFLAGS   += -L$(cwelke_tools) 

# add sharedCode support
cwelke_shared  := ../sharedCode
CPPFLAGS  += -I$(cwelke_shared) 
LDFLAGS   += -L$(cwelke_shared) 

# create the dict.cc
$(rootdict): $(headers)
	$(call root-cint,$(rootdict),$(headers),$(include_dir),$(link_def),$(defines))

# project specific variables 
# ----------------------------------------------------------------------- #

lib := libmakePhotonTemplates.so

sources := makePhotonTemplates.cc                      \
		   $(cwelke_shared)/ZMET.cc                    \
		   $(cwelke_shared)/METTemplateSelections.cc   \
		   $(cwelke_shared)/histTools.cc 

objects := $(subst .cc,.o,$(sources)) makePhotonTemplates_dict.o


# rules 
# ----------------------------------------------------------------------- #

# all rule should be first
.PHONY: all
all: library 

# for troubleshooting
.PHONY: test
test: 
	@echo lib = $(lib)
	@echo sources       = $(sources)
	@echo objects       = $(objects)
	@echo SHAREDLIB.cc  = $(SHAREDLIB.cc)
	@echo cwelke_tools  = $(cwelke_tools)
	@echo cwelke_shared = $(cwelke_shared)
	@echo LDFLAGS       = $(LDFLAGS)
	@echo CPPFLAGS      = $(CPPFLAGS)

# build the library 
.PHONY: library
library: $(lib)

.PHONY: clean
clean:
	rm $(objects) $(lib) makePhotonTemplates_dict.{cc,h} 

# actual rule to build the library
$(lib) : $(objects)
	$(SHAREDLIB.cc) $@ $^

# root to build the ROOT CINT dictionary
makePhotonTemplates_dict.cc : makePhotonTemplates.h #Z_looper.h
	rootcint -v3 -f $@ -c -DNDEBUG $^ LinkDef.h 

