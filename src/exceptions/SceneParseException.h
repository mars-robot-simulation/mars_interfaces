#pragma once

#include <exception>
#include <string>
#include <sstream>

namespace mars
{
    namespace interfaces
    {

        class SceneParseException : public std::exception
        {
        public:
            SceneParseException(const std::string &info, int line=-1,
                                const std::string &file="") throw()
                : line(line), file(file)
            {

                std::stringstream s;
                s << "Error in scene file";
        
                //if a filename is given
                if(file.size())
                {
                    s << " \"" << file << "\"";
                }
        
                //if a line number is given
                if(line != -1)
                {
                    s << " in line " << line;
                }

                s << ": " << info;
                message = s.str();
            }
      
            virtual ~SceneParseException() throw()
            {}
      
            virtual const char* what()
            {
                return message.c_str();
            }

            int getLine()
            {
                return line;
            }

            const char* getFile()
            {
                return file.c_str();
            }

            const char* getInfo()
            {
                return info.c_str();
            }

        protected:
            ///if known, the line where the error occured
            int line;

            ///if known, the filename of the scene file.
            std::string file;

            ///informative text to the user (without filename and line).
            std::string info;

            ///informative text including line and filename.
            std::string message;
        }; // end of class SceneParseException

    } // end of namespace interfaces
} // end of namespace mars
