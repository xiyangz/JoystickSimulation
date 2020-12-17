// JoystickSimulation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
//#include <csignal>
//#include "ViGEmClient.h"
//#include "hidapi.h"

//#pragma comment(lib,"hidapi.lib")
//#pragma comment(lib,"ViGEmClient.lib")
#using "Nefarius.ViGEm.Client.dll"
using namespace Nefarius::ViGEm::Client; 
using namespace Nefarius::ViGEm::Client::Targets;
using namespace Nefarius::ViGEm::Client::Targets::Xbox360;

//PVIGEM_CLIENT client = nullptr; //Allocates an object representing a driver connection.
//PVIGEM_TARGET target = nullptr; // Allocates an object representing which controller device.
//XUSB_REPORT report;//Represents an XINPUT_GAMEPAD-compatible report structure.
//
//std::string vigem_error_to_string(VIGEM_ERROR err) {
//    switch (err) {
//    case VIGEM_ERROR_NONE: return "none";
//    case VIGEM_ERROR_ALREADY_CONNECTED: return "already connected";
//    case VIGEM_ERROR_BUS_ACCESS_FAILED: return "bus access failed";
//    case VIGEM_ERROR_BUS_ALREADY_CONNECTED: return "bus already connected";
//    case VIGEM_ERROR_BUS_NOT_FOUND: return "bus not found";
//    case VIGEM_ERROR_BUS_VERSION_MISMATCH: return "bus version mismatch";
//    case VIGEM_ERROR_CALLBACK_ALREADY_REGISTERED: return "callback already registered";
//    case VIGEM_ERROR_CALLBACK_NOT_FOUND: return "callback not found";
//    case VIGEM_ERROR_INVALID_TARGET: return "invalid target";
//    case VIGEM_ERROR_NO_FREE_SLOT: return "no free slot";
//    case VIGEM_ERROR_REMOVAL_FAILED: return "removal failed";
//    case VIGEM_ERROR_TARGET_NOT_PLUGGED_IN: return "target not plugged in";
//    case VIGEM_ERROR_TARGET_UNINITIALIZED: return "target uninitialized";
//    default: return "none";
//    }
//}
//
////由于ViGEmBus只支持Microsoft Xbox 360 Controller 和 Sony DualShock 4 Controller
//void initialize_xbox() {
//    std::cout << "initializing emulated Xbox 360 controller..." << std::endl;
//    client = vigem_alloc();
//    VIGEM_ERROR err = vigem_connect(client);
//    if (err == VIGEM_ERROR_NONE) {
//        std::cout << " => connected successfully" << std::endl;
//    }
//    else {
//        std::cout << "connection error: " << vigem_error_to_string(err) << std::endl;
//        vigem_free(client);
//        std::cout << "press [ENTER] to exit" << std::endl;
//        getchar();
//        exit(1);
//    }
//    target = vigem_target_x360_alloc();
//    vigem_target_add(client, target);
//    XUSB_REPORT_INIT(&report);
//    std::cout << " => added target Xbox 360 Controller" << std::endl;
//    std::cout << std::endl;
//}
//
//void quit() {
//    hid_exit();
//    vigem_target_remove(client, target);
//    vigem_target_free(target);
//    vigem_disconnect(client);
//    vigem_free(client);
//    exit(0);
//}
//
//void exit_handler(int signum) {
//    quit();
//    exit(signum);
//}

// vigem_target_x360_update函数

int main()
{

    ViGEmClient^ client = gcnew ViGEmClient();

    IXbox360Controller^ controller = client->CreateXbox360Controller();

    controller->Connect();
    Sleep(100);
    //minimum of -32768, maximum of 32767
    controller->SetAxisValue(Xbox360Axis::LeftThumbX, -32768);

    //true or false
    controller->SetButtonState(Xbox360Button::X, true);

    //minimum of 0, maximum of 255
    controller->SetSliderValue(Xbox360Slider::LeftTrigger, 255);

    //int ch = Console.Read();

    //while(ch != 'q' && ch != 'Q')
    //{
    //    controller.SetButtonState(Xbox360Button.B, true);
    //    ch = Console.Read();
    //}

    Sleep(5000);

 /*   signal(SIGINT, exit_handler);

    initialize_xbox();
    hid_init();
    
    int ch = getchar();
    while (ch != 'Q' && ch != 'q')
    {
        report.sThumbLX = 255;
        report.wButtons
        vigem_target_x360_update(client, target, report);
        ch = getchar();
    }
    
    quit();*/
}
