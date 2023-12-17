#include <iostream>
#include <string>
#include "./src/parser.cpp"
using namespace std;

int main()
{
    std::string html = R"(<html>
<head>
    <meta>
    <title></title>
</head>
<body>
    <h1 id="heading"><h2></h2></h1>
    <p><p><a><img><h3></h3></a></p></p>
    <a></a>
    <img>
</body>
</html>)";

    // Parse the HTML into a Tree
    Tree *parsedTree = Parser::parseHTML(html);

    // Display the parsed tree
    parsedTree->display();
    return 0;
}