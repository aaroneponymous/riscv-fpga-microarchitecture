#pragma once
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string_view>
#include <vector>


/**
 * For RV32I, the 32 x registers are each 32 bits wide
 * i.e., XLEN=32. Register x0 is hardwired with all bits equal to 0.
 * General purpose registers x1-x31 hold values that various instructions interpret as a collection of Boolean values,
 * or as two’s complement signed binary integers or unsigned binary integers.
 *
 * There is one additional unprivileged register: the program counter pc holds the address of the current instruction.
 *
 */

/**
 * There is no dedicated stack pointer or subroutine return address link register in the Base Integer ISA;
 * the instruction encoding allows any x register to be used for these purposes.
 *
 * However, the standard software calling convention uses register x1 to hold the return address for a call,
 * with register x5 available as an alternate link register.
 *
 * The standard calling convention uses register x2 as the stack pointer.
 *
 *  Standard Registers for SP and Return Address for a Call:
 *  - Stack Pointer  [SP]: x2
 *  - Return Address [RA]: x5 or x1
 *
 *
 *  The optional compressed 16-bit instruction format is designed around the assumption
 *  that x1 is the return address register and x2 is the stack pointer
 *
 *
 */



struct CPU
{
    std::array<uint32_t, 32>    reg{};
    uint32_t                    pc{};
    std::vector<std::byte>      memory;
};



enum class register_id : std::uint8_t
{
    x0,
    x1,
    x2,
    x3,
    x4,
    x5,
    x6,
    x7,
    x8,
    x9,
    x10,
    x11,
    x12,
    x13,
    x14,
    x15,
    x16,
    x17,
    x18,
    x19,
    x20,
    x21,
    x22,
    x23,
    x24,
    x25,
    x26,
    x27,
    x28,
    x29,
    x30,
    pc

};

enum class opcode : std::uint8_t
{
    LOAD = 0x3,
    STORE = 0x23
};

enum class load_funct : std::uint8_t
{
    LB  = 0x0,
    LH  = 0x1,
    LW  = 0x2,
    LBU = 0x4,
    LHU = 0x5
};


enum class store_funct : std::uint8_t
{
    SB  = 0x0,
    SH  = 0x1,
    SW  = 0x2
};

// First Phase:  Assembly Instruction to Machine Code
// Second Phase: Machine Encoded Instruction to Decoding & Executing Pipeline

static constexpr std::uint8_t opcode_mask = 0x7F;
static constexpr std::uint8_t store_op    = 0x23;



static constexpr void execute_instruction(std::uint32_t const instruction)
{
    // Opcode Decoder & Family & Function
    if (std::uint8_t const opcode = (instruction & opcode_mask); opcode == store_op)
    {
        std::uint8_t const func_type        = (instruction >> 0xC) & 0x7;
        std::uint8_t const rs_1             = (instruction >> 0xF) & 0x1F;
        std::uint8_t const rs_2             = (instruction >> 0x14) & 0x1F;

        std::int32_t const offset_low       = (static_cast<std::int32_t>(instruction) >> 0x7) & 0x1F;
        std::int32_t const offset_high      = (static_cast<std::int32_t>(instruction) >> 0x12) & 0xFFFFFF80; // NOLINT(*-narrowing-conversions)

        std::int32_t const immediate_offset = offset_high + offset_low;

        // LW: 0x2








    }
    else {
        throw std::logic_error("Invalid Opcode in Instruction");
    }





}
















































