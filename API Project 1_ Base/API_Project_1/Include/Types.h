#pragma once

typedef struct _tagResolution {

	unsigned int width;
	unsigned int height;
	void SetSize(int width, int height) {
		this->width = width;
		this->height = height;
	}
}RESOLUTION, *PRESOLUTION;