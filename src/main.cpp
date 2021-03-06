#include <iostream>
#include "store_server.h"
#include "test/dotest.h"
using namespace std;
using namespace kvstore;


int main()
{
    //设置log输出到控制台，并且保存到文件
    logging::Logger::set_output(logging::LogRecorder::callback());
    //logging::Logger::set_level(logging::Logger::eINFO);
    logging::Logger::set_level(logging::Logger::eDEBUG);
    //logging::Logger::set_no_display_function(true);
    boost::asio::io_service ioservice;
    std::size_t port = 23333;
    StoreServer server(ioservice, port);
    server.init();
    //做测试入口
    test::do_test(ioservice);
    ioservice.run();
    cout << "Hello World!" << endl;
    return 0;
}





