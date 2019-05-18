#include <iomanip>

#pragma warning(push, 0)
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_draw.H>
#pragma warning(pop)

#include "themes.h"
#include "event.h"
#include "main-window.h"

static uchar texture_red16_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x01, 0x03, 0x00, 0x00, 0x00, 0x25, 0x3d, 0x6d,
	0x22, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0xff, 0x00, 0x00, 0xcd, 0x00, 0x00, 0xd8,
	0xd4, 0x17, 0x10, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0xf8, 0xff, 0x9f, 0xa1,
	0x81, 0x91, 0x58, 0xf4, 0xff, 0x3f, 0x00, 0x0c, 0xa8, 0x0b, 0x0b, 0xc4, 0x92, 0xc3, 0x60, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_green16_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x01, 0x03, 0x00, 0x00, 0x00, 0x25, 0x3d, 0x6d,
	0x22, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x00, 0xa0, 0x00, 0x00, 0x6e, 0x00, 0x2e,
	0x3e, 0x60, 0x70, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0xf8, 0xff, 0x9f, 0xa1,
	0x81, 0x91, 0x58, 0xf4, 0xff, 0x3f, 0x00, 0x0c, 0xa8, 0x0b, 0x0b, 0xc4, 0x92, 0xc3, 0x60, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_blue16_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x01, 0x03, 0x00, 0x00, 0x00, 0x25, 0x3d, 0x6d,
	0x22, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x30, 0x30, 0xff, 0x00, 0x00, 0xcd, 0x3b,
	0xec, 0xbe, 0x18, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0xf8, 0xff, 0x9f, 0xa1,
	0x81, 0x91, 0x58, 0xf4, 0xff, 0x3f, 0x00, 0x0c, 0xa8, 0x0b, 0x0b, 0xc4, 0x92, 0xc3, 0x60, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_purple16_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x01, 0x03, 0x00, 0x00, 0x00, 0x25, 0x3d, 0x6d,
	0x22, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0xa0, 0x00, 0xa0, 0x6e, 0x00, 0x6e, 0x19,
	0x53, 0x1b, 0x51, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0xf8, 0xff, 0x9f, 0xa1,
	0x81, 0x91, 0x58, 0xf4, 0xff, 0x3f, 0x00, 0x0c, 0xa8, 0x0b, 0x0b, 0xc4, 0x92, 0xc3, 0x60, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_orange16_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x01, 0x03, 0x00, 0x00, 0x00, 0x25, 0x3d, 0x6d,
	0x22, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0xff, 0x80, 0x00, 0xcd, 0x4e, 0x00, 0x07,
	0xc8, 0xc5, 0x09, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0xf8, 0xff, 0x9f, 0xa1,
	0x81, 0x91, 0x58, 0xf4, 0xff, 0x3f, 0x00, 0x0c, 0xa8, 0x0b, 0x0b, 0xc4, 0x92, 0xc3, 0x60, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_azure16_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x01, 0x03, 0x00, 0x00, 0x00, 0x25, 0x3d, 0x6d,
	0x22, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x00, 0x80, 0xff, 0x00, 0x4e, 0xcd, 0x41,
	0xab, 0xd3, 0x2a, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0xf8, 0xff, 0x9f, 0xa1,
	0x81, 0x91, 0x58, 0xf4, 0xff, 0x3f, 0x00, 0x0c, 0xa8, 0x0b, 0x0b, 0xc4, 0x92, 0xc3, 0x60, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_red32_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x01, 0x03, 0x00, 0x00, 0x00, 0x49, 0xb4, 0xe8,
	0xb7, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0xcd, 0x00, 0x00, 0xff, 0x00, 0x00, 0xb6,
	0x89, 0x80, 0x48, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0x00, 0x83, 0xfa, 0xff,
	0xff, 0xff, 0x0d, 0x3e, 0x02, 0x04, 0x00, 0x8d, 0x4d, 0x68, 0x6b, 0x67, 0xaf, 0xc3, 0x69, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_green32_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x01, 0x03, 0x00, 0x00, 0x00, 0x49, 0xb4, 0xe8,
	0xb7, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x00, 0x6e, 0x00, 0x00, 0xa0, 0x00, 0x2d,
	0x62, 0xcc, 0x0a, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0x00, 0x83, 0xfa, 0xff,
	0xff, 0xff, 0x0d, 0x3e, 0x02, 0x04, 0x00, 0x8d, 0x4d, 0x68, 0x6b, 0x67, 0xaf, 0xc3, 0x69, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_blue32_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x01, 0x03, 0x00, 0x00, 0x00, 0x49, 0xb4, 0xe8,
	0xb7, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x00, 0x00, 0xcd, 0x30, 0x30, 0xff, 0xf7,
	0x6f, 0xb3, 0xfa, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0x00, 0x83, 0xfa, 0xff,
	0xff, 0xff, 0x0d, 0x3e, 0x02, 0x04, 0x00, 0x8d, 0x4d, 0x68, 0x6b, 0x67, 0xaf, 0xc3, 0x69, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_purple32_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x01, 0x03, 0x00, 0x00, 0x00, 0x49, 0xb4, 0xe8,
	0xb7, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x6e, 0x00, 0x6e, 0xa0, 0x00, 0xa0, 0x43,
	0xce, 0xa9, 0x5d, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0x00, 0x83, 0xfa, 0xff,
	0xff, 0xff, 0x0d, 0x3e, 0x02, 0x04, 0x00, 0x8d, 0x4d, 0x68, 0x6b, 0x67, 0xaf, 0xc3, 0x69, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_orange32_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x01, 0x03, 0x00, 0x00, 0x00, 0x49, 0xb4, 0xe8,
	0xb7, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0xcd, 0x4e, 0x00, 0xff, 0x80, 0x00, 0x6a,
	0xc9, 0xfe, 0x2b, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0x00, 0x83, 0xfa, 0xff,
	0xff, 0xff, 0x0d, 0x3e, 0x02, 0x04, 0x00, 0x8d, 0x4d, 0x68, 0x6b, 0x67, 0xaf, 0xc3, 0x69, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static uchar texture_azure32_png_buffer[107] = {
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x01, 0x03, 0x00, 0x00, 0x00, 0x49, 0xb4, 0xe8,
	0xb7, 0x00, 0x00, 0x00, 0x06, 0x50, 0x4c, 0x54, 0x45, 0x00, 0x4e, 0xcd, 0x00, 0x80, 0xff, 0xd0,
	0x02, 0x1e, 0xfa, 0x00, 0x00, 0x00, 0x02, 0x74, 0x52, 0x4e, 0x53, 0x80, 0x80, 0xa0, 0xa8, 0xd6,
	0x53, 0x00, 0x00, 0x00, 0x12, 0x49, 0x44, 0x41, 0x54, 0x78, 0x5e, 0x63, 0x00, 0x83, 0xfa, 0xff,
	0xff, 0xff, 0x0d, 0x3e, 0x02, 0x04, 0x00, 0x8d, 0x4d, 0x68, 0x6b, 0x67, 0xaf, 0xc3, 0x69, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static Fl_PNG_Image texture_images[NUM_EVENT_TEXTURES] = {
	{NULL, texture_red16_png_buffer,    107}, // TX_RED
	{NULL, texture_green16_png_buffer,  107}, // TX_GREEN
	{NULL, texture_blue16_png_buffer,   107}, // TX_BLUE
	{NULL, texture_purple16_png_buffer, 107}, // TX_PURPLE
	{NULL, texture_orange16_png_buffer, 107}, // TX_ORANGE
	{NULL, texture_azure16_png_buffer,  107}  // TX_AZURE
};

static Fl_PNG_Image zoomed_texture_images[NUM_EVENT_TEXTURES] = {
	{NULL, texture_red32_png_buffer,    107}, // TX_RED
	{NULL, texture_green32_png_buffer,  107}, // TX_GREEN
	{NULL, texture_blue32_png_buffer,   107}, // TX_BLUE
	{NULL, texture_purple32_png_buffer, 107}, // TX_PURPLE
	{NULL, texture_orange32_png_buffer, 107}, // TX_ORANGE
	{NULL, texture_azure32_png_buffer,  107}  // TX_AZURE
};

Event::Event(size_t line, std::string prelude, std::string macro, Event_Meta meta, std::string tip_) : Fl_Box(0, 0, 0, 0),
	_line(line), _meta(meta), _event_x(0), _event_y(0), _prelude(prelude), _macro(macro), _prefix(), _suffix(),
	_tip(tip_), _prefixed(false), _suffixed(false), _hex_coords(false) {
	user_data(NULL);
	trim(_tip);
	tip(_tip);
}

bool Event::warp_map_name(char *name) const {
	if (_meta.warp <= 0) { return false; }
	std::istringstream ss(_suffix);
	std::string token;
	for (uint8_t i = 0; i <= _meta.warp; i++) {
		if (!ss.good()) { return false; }
		std::getline(ss, token, ',');
	}
	trim(token);
	bool downcase = false;
	for (char &c : token) {
		if (downcase) {
			c = (char)tolower(c);
		}
		if (c == '_') {
			downcase = false;
		}
		else {
			*name++ = c;
			downcase = !isdigit(c);
		}
	}
	*name = '\0';
	return true;
}

static uint8_t parse_coord(std::string s, bool &hex) {
	int n = 0;
	trim(s);
	if (!s.empty()) {
		if (s[0] == '$') {
			s.erase(0, 1);
			n = std::stoi(s, NULL, 16);
			hex = true;
		}
		else if (s[0] == '%') {
			s.erase(0, 1);
			n = std::stoi(s, NULL, 2);
		}
		else {
			n = std::stoi(s, NULL);
		}
	}
	return (uint8_t)n;
}

void Event::parse(std::istringstream &lss) {
	std::string token;
	_prefixed = _meta.skip > 0;
	for (uint8_t i = 0; i < _meta.skip; i++) {
		std::getline(lss, token, ',');
		_prefix += token + ',';
	}
	std::getline(lss, token, ',');
	_event_x = parse_coord(token, _hex_coords);
	std::getline(lss, token);
	size_t sep = MIN(token.find(','), token.find(';'));
	_suffixed = sep != std::string::npos;
	if (_suffixed) {
		_suffix = token.substr(sep);
		token.erase(sep);
	}
	_event_y = parse_coord(token, _hex_coords);
	if (_meta.yx) {
		std::swap(_event_x, _event_y);
	}
}

void Event::update_tooltip() {
	std::ostringstream ss;
	ss << _macro << ' ';
	if (_prefixed) { ss << _prefix << ' '; }
	ss << (_hex_coords ? std::hex : std::dec);
	if (_hex_coords) { ss << '$'; }
	else { ss << std::right << std::setw(2); }
	ss << (int)(_meta.yx ? _event_y : _event_x);
	ss << ", ";
	if (_hex_coords) { ss << '$'; }
	else { ss << std::right << std::setw(2); }
	ss << (int)(_meta.yx ? _event_x : _event_y);
	ss << std::setw(1);
	if (_suffixed) { ss << _suffix; }
	tip(ss.str());
}

void Event::draw() {
	Main_Window *mw = (Main_Window *)user_data();
	if (mw->mode() != Mode::EVENTS && !mw->show_events()) { return; }
	int X = x(), Y = y(), W = w(), H = h();
	bool zoom = mw->zoom();
	(zoom ? zoomed_texture_images : texture_images)[_meta.texture].draw(X, Y, W, H);
	fl_font(FL_HELVETICA_BOLD, zoom ? 24 : 14);
	fl_color(FL_WHITE);
	char buffer[2] = {_meta.symbol, '\0'};
	fl_draw(buffer, X, Y, W, H, FL_ALIGN_CENTER);
	fl_font(OS_FONT, OS_FONT_SIZE);
	if (Fl::belowmouse() != this) { return; }
	fl_rect(X, Y, W, H, FL_BLACK);
	fl_rect(X+1, Y+1, W-2, H-2, FL_WHITE);
	if (zoom) {
		fl_rect(X+2, Y+2, W-4, H-4, FL_WHITE);
		fl_rect(X+3, Y+3, W-6, H-6, FL_BLACK);
	}
	else {
		fl_rect(X+2, Y+2, W-4, H-4, FL_BLACK);
	}
}

int Event::handle(int event) {
	Main_Window *mw = (Main_Window *)user_data();
	if (mw->mode() != Mode::EVENTS) { return 0; }
	switch (event) {
	case FL_ENTER:
		mw->update_status(this);
		redraw();
		return 1;
	case FL_LEAVE:
		mw->update_status((Event *)NULL);
		redraw();
		return 1;
	case FL_MOVE:
		mw->redraw_map();
		return 1;
	case FL_PUSH:
		return 1;
	case FL_RELEASE:
		if (Fl::event_shift()) {
			do_callback();
		}
		else {
			do_callback();
			update_tooltip();
			mw->update_event_cursor(this);
		}
		return 1;
	case FL_DRAG:
		if (Fl::event_button() == FL_LEFT_MOUSE && !Fl::event_shift()) {
			do_callback();
		}
		return 1;
	}
	return 0;
}
