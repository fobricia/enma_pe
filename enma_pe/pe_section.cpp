#include "stdafx.h"
#include "pe_section.h"


pe_section::pe_section() {
	name.clear();
	virtual_size		= 0;
	virtual_address		= 0;
	pointer_to_raw		= 0;
	characteristics		= 0;

	section_data.clear();
}
pe_section::pe_section(const pe_section& section) {
	this->name				= section.name;
	this->virtual_size		= section.virtual_size;
	this->virtual_address	= section.virtual_address;
	this->pointer_to_raw	= section.pointer_to_raw;
	this->characteristics	= section.characteristics;
	this->section_data		= section.section_data;
}

pe_section::pe_section(const IMAGE_SECTION_HEADER& header) {
	this->name.reserve(8);
	this->name.resize(lstrlenA((char*)header.Name));
	memcpy((void*)this->name.data(), header.Name,8);

	this->virtual_size		= header.Misc.VirtualSize;
	this->virtual_address	= header.VirtualAddress;
	this->pointer_to_raw	= header.PointerToRawData;
	this->characteristics	= header.Characteristics;

	this->section_data.clear();
}
pe_section::pe_section(const IMAGE_SECTION_HEADER& header, const std::vector<BYTE>& data) {
	this->name.reserve(8);
	this->name.resize(lstrlenA((char*)header.Name));
	memcpy((void*)this->name.data(), header.Name, 8);

	this->virtual_size		= header.Misc.VirtualSize;
	this->virtual_address	= header.VirtualAddress;
	this->pointer_to_raw	= header.PointerToRawData;
	this->characteristics	= header.Characteristics;

	this->section_data = data;
}
pe_section::~pe_section() {

}

pe_section& pe_section::operator=(const pe_section& section) {
	this->name = section.name;
	this->virtual_size		= section.virtual_size;
	this->virtual_address	= section.virtual_address;
	this->pointer_to_raw	= section.pointer_to_raw;
	this->characteristics	= section.characteristics;
	this->section_data		= section.section_data;
	return *this;
}

pe_section& pe_section::set_name(std::string name) {
	this->name = name;
	return *this;
}
pe_section& pe_section::set_virtual_size(DWORD virtual_size) {
	this->virtual_size = virtual_size;
	return *this;
}
pe_section& pe_section::set_virtual_address(DWORD virtual_address) {
	this->virtual_address = virtual_address;
	return *this;
}
pe_section& pe_section::set_size_of_raw_data(DWORD size_of_raw_data) {
	section_data.resize(size_of_raw_data);
	return *this;
}
pe_section& pe_section::set_pointer_to_raw(DWORD pointer_to_raw) {
	this->pointer_to_raw = pointer_to_raw;
	return *this;
}
pe_section& pe_section::set_characteristics(DWORD characteristics) {
	this->characteristics = characteristics;
	return *this;
}

pe_section& pe_section::set_readable(bool flag) {
	if (flag) {
		this->characteristics |= IMAGE_SCN_MEM_READ;
	}
	else {
		this->characteristics = ~((~this->characteristics) | IMAGE_SCN_MEM_READ);
	}
	return *this;
}
pe_section& pe_section::set_writeable(bool flag) {
	if (flag) {
		this->characteristics |= IMAGE_SCN_MEM_WRITE;
	}
	else {
		this->characteristics = ~((~this->characteristics) | IMAGE_SCN_MEM_WRITE);
	}
	return *this;
}
pe_section& pe_section::set_executable(bool flag) {
	if (flag) {
		this->characteristics |= IMAGE_SCN_MEM_EXECUTE;
	}
	else {
		this->characteristics = ~((~this->characteristics) | IMAGE_SCN_MEM_EXECUTE);
	}
	return *this;
}

void pe_section::add_data(void * data, unsigned int data_size) {
	section_data.resize(section_data.size() + data_size);
	memcpy(section_data.data() + section_data.size() - data_size, data, data_size);
}

std::string pe_section::get_name() const {
	return name;
}
DWORD pe_section::get_virtual_size() const {
	return virtual_size;
}
DWORD pe_section::get_virtual_address() const {
	return virtual_address;
}
DWORD pe_section::get_size_of_raw_data() const {
	return section_data.size();
}
DWORD pe_section::get_pointer_to_raw() const {
	return pointer_to_raw;
}
DWORD pe_section::get_characteristics() const {
	return characteristics;
}

bool pe_section::is_readable() const {
	return (characteristics&IMAGE_SCN_MEM_READ) != 0;
}
bool pe_section::is_writeable() const {
	return (characteristics&IMAGE_SCN_MEM_WRITE) != 0;
}
bool pe_section::is_executable() const {
	return (characteristics&IMAGE_SCN_MEM_EXECUTE) != 0;
}

std::vector<BYTE>& pe_section::get_section_data() {
	return section_data;
}