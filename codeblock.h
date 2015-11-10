#ifndef CODEBLOCK_H
#define CODEBLOCK_H
#include "codesentence.h"
#include <vector>

class CodeBlock : public CodeSentence
{
    vector<CodeSentence *> sentences;
public:
    CodeBlock();
    virtual ~CodeBlock();
};

#endif // CODEBLOCK_H
