#include "../../../AHRS_core/src/model/hardware/hw/extendables/SerialDevice.hpp"
#include "ThermxRenderer.hpp"
class ThermxController : public SerialDevice{
    protected:
            float out_buf[24][32];
            ThermxRenderer* _trx;
    public:
        ThermxController(ThermxRenderer* trx) : SerialDevice("/dev/ttyACM"), _trx(trx){
            ic = new IdentifiyCommand(this);
            this->_tagidentifier = "821ce9ba-a697-487b-a402-32e29b9d599d";
            this->_displayName = "thermal camera module";
            this->_baudrate = 460800;
        }

        void getData();
};

class ThermXRefreshDataCommand : public DeviceCommand{
    ThermxController* _controller;

    public:
    ThermXRefreshDataCommand(ThermxController* controller){
        displayed = false;
        descriptor = "refresh thermal data";
        identifier = "refresh";
        millisDelayReapeated = 55;
        _controller = controller;
    }

    void Execute() const override{
        _controller->getData();
    }
};