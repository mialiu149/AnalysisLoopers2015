Useful commands:

Tagging your code

git tag -a <version> -m 'add a message'

git push --tags

When you checkout the repository, you need to make sure the CMS2 header files in CORE are up to date with the version of CMS3 ntuples you are running over. I included a version of the header files in the folder CMS2Headers which correspond to branch CMS3_V07-02-04. These will be updated as CMS3 evolves. When using this baby maker, make sure to copy the header files from this directory to the CORE directory before compiling.


Repo Usage:

git clone git@github.com:mialiu149/AnalysisLoopers2015.git

cd AnalysisLoopers2015

git clone git@github.com:cmstas/Software.git

git clone git@github.com:cmstas/CORE.git

Edit COREPATH and Software path in setup.sh, edit project name, version in settings.sh

setup CMSSW
source setup.sh

cd project_dir
make -j25
