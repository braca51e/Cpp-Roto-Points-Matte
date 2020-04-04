#include <iostream>
#include <experimental/filesystem>
#include <boost/algorithm/string.hpp>
#include "MatteProcessing.h"
#include "argparse.h"

std::vector<std::string> get_filenames( std::experimental::filesystem::path path )
{
    namespace stdfs = std::experimental::filesystem ;

    std::vector<std::string> filenames ;

    // http://en.cppreference.com/w/cpp/experimental/fs/directory_iterator
    const stdfs::directory_iterator end{} ;

    for( stdfs::directory_iterator iter{path} ; iter != end ; ++iter )
    {
        // http://en.cppreference.com/w/cpp/experimental/fs/is_regular_file
        if( stdfs::is_regular_file(*iter) && boost::algorithm::contains(iter->path().string(), ".png")) // comment out if all names (names of directories tc.) are required
            filenames.push_back( iter->path().string() ) ;
    }

    return filenames ;
}

/* Main function */
int main(int argc, const char* argv[])
{
    ArgumentParser parser;
    parser.addArgument("-i", "--input", 1, true);
    parser.parse(argc, argv);
    std::string folderPath = parser.retrieve<std::string>("input");

    // Begin Matte extraction
    std::unique_ptr<MatteProcessing> matteProcessing = std::make_unique<MatteProcessing>();
    for(const auto& name : get_filenames(folderPath)){
        std::cout << "processing image: " << name << std::endl;
        matteProcessing->processMatte(name);
    }

    return EXIT_SUCCESS;
}
