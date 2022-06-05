#pragma once
/**
 * @file messages.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include<string>

const std::string_view EXITED_sv = "Exited.";
const std::string EXITED = "Exited.";

const std::string ERR_INCORRECT = "Incorrect input.";
const std::string ERR_MANY = "Too many inputs.";
const std::string ERR_EMPTY = "Empty input.";

const std::string FILE_t = "file";
const std::string DIR_t = "directory";
const std::string TYPE_t = "type";


const std::string CMD_BACK = "back";
const std::string CMD_HELP = "help";

const std::string CMD_TRANSITION = "transition";
const std::string CMD_CUSTOM = "custom";

const std::string CMD_ROTATER = "rotateR";
const std::string CMD_ROTATEL = "rotateL";
const std::string CMD_MIRROR = "mirror"; 
const std::string CMD_FLIP = "flip"; 
const std::string CMD_BRIGHT = "bright"; 
const std::string CMD_DARK = "dark"; 
const std::string CMD_INVERT = "invert"; 
const std::string CMD_UPSIZE = "upsize"; 
const std::string CMD_DOWNSIZE = "downsize";

const std::string ERR_RANGE = "Index out of range.";

const std::string CMD_ADD = "add";
const std::string CMD_REMOVE = "remove";
const std::string CMD_PLAY = "play";
const std::string CMD_SWITCH = "switch";
const std::string CMD_SHOW = "show";

const std::string ANSI_CLEAR = "\x1B[2J\x1B[H";


