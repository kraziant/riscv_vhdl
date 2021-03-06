/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      GPIO functional model.
 */

#ifndef __DEBUGGER_SOCSIM_PLUGIN_GPIO_H__
#define __DEBUGGER_SOCSIM_PLUGIN_GPIO_H__

#include "iclass.h"
#include "iservice.h"
#include "coreservices/imemop.h"
#include "coreservices/iwire.h"

namespace debugger {

class GPIO : public IService, 
             public IMemoryOperation,
             public IWire {
public:
    GPIO(const char *name);
    ~GPIO();

    /** IService interface */
    virtual void postinitService();

    /** IMemoryOperation */
    virtual ETransStatus b_transport(Axi4TransactionType *trans);

    /** IWire interface */
    virtual void raiseLine() {}
    virtual void lowerLine() {}
    virtual void setLevel(bool level) {}
    virtual bool getLevel() { return 0; }

private:
    AttributeType dip_;

    struct gpio_map {
        volatile uint32_t led;
        volatile uint32_t dip;
        volatile uint32_t reg2;
        volatile uint32_t reg3;
        volatile uint32_t led_period;
        volatile uint32_t reg5;
        volatile uint32_t reg6;
    } regs_;
};

DECLARE_CLASS(GPIO)

}  // namespace debugger

#endif  // __DEBUGGER_SOCSIM_PLUGIN_GPIO_H__
