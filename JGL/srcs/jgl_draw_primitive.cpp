#include "jgl.h"

namespace jgl
{
	jgl::Array<Vector2> calc_point(const size_t width)
	{
		jgl::Array<Vector2> result;
		int tmp;

		if (width % 2 == 0)
			tmp = width + 1;
		else
			tmp = width;

		for (int i = 0; i <= tmp / 2; i++)
			for (int j = 0; j <= tmp / 2; j++)
			{
				result.push_back(jgl::Vector2(i, j));
				if (i != 0 && j != 0)
					result.push_back(jgl::Vector2(-i, -j));
				if (i == 0 && j != 0)
					result.push_back(jgl::Vector2(i, -j));
				if (i != 0 && j == 0)
					result.push_back(jgl::Vector2(-i, j));
			}

		return (result);
	}

	void draw_line(const Vector2 p1, const Vector2 p2, const size_t width, const Color p_color, const Viewport* viewport)
	{
		if (viewport != nullptr)
			viewport->use();

		jgl::Array<Vector2> to_draw = calc_point(width);
		static jgl::Array<Vector3> points;
		static jgl::Array<Color> colors;

		points.clear();
		colors.clear();

		for (size_t i = 0; i < to_draw.size(); i++)
		{
			points.push_back(convert_screen_to_opengl(p1 + to_draw[i]));
			points.push_back(convert_screen_to_opengl(p2 + to_draw[i]));
			colors.push_back(p_color);
			colors.push_back(p_color);
		}
		draw_line_color(points.all(), colors.all(), points.size());
		
	}

	void draw_point(const Vector2 center, const size_t width, const Color p_color, const Viewport* viewport)
	{
		if (viewport != nullptr)
			viewport->use();

		Vector3 tmp_center = 0;
		Vector3 actual;

		for (actual.x = -static_cast<int>(width) / 2.0f; actual.x <= static_cast<int>(width) / 2.0f || actual.x == 0; actual.x++)
		{
			for (actual.y = -static_cast<int>(width) / 2.0f; actual.y <= static_cast<int>(width) / 2.0f || actual.y == 0; actual.y++)
			{
				if (tmp_center.distance(actual) < width / 2.0f)
					draw_pixel_color(Vector3(actual.x + center.x, actual.y + center.y, 0.0f), p_color);
			}
		}
	}

	void draw_rectangle(const Vector2 p_tl, const Vector2 p_tr, const Vector2 p_dl, const Vector2 p_dr, const size_t width, const Color p_color, const Viewport* viewport)
	{
		if (viewport != nullptr)
			viewport->use();

		draw_line(p_tl, p_tr, width, p_color, viewport);
		draw_line(p_tl, p_dl, width, p_color, viewport);
		draw_line(p_dl, p_dr, width, p_color, viewport);
		draw_line(p_tr, p_dr, width, p_color, viewport);
	}

	void fill_rectangle(const Vector2 p_tl, const Vector2 p_tr, const Vector2 p_dl, const Vector2 p_dr, const Color p_color, const Viewport* viewport)
	{
		if (viewport != nullptr)
			viewport->use();

		Vector3 points[] = {
			convert_screen_to_opengl(p_tl),
			convert_screen_to_opengl(p_dr),
			convert_screen_to_opengl(p_tr),
			convert_screen_to_opengl(p_dl),
			convert_screen_to_opengl(p_dr),
			convert_screen_to_opengl(p_tl)
		};
		Color colors[] = {
			p_color,
			p_color,
			p_color,
			p_color,
			p_color,
			p_color
		};

		fill_triangle_color(points, colors, 6);
	}

	void draw_rectangle(const Vector2 pos, const Vector2 size, const size_t width, const Color p_color, const Viewport* viewport)
	{
		draw_rectangle(pos, Vector2(pos.x + size.x, pos.y), Vector2(pos.x, pos.y + size.y), pos + size, width, p_color, viewport);
	}

	void fill_rectangle(const Vector2 pos, const Vector2 size, const Color p_color, const Viewport* viewport)
	{
		fill_rectangle(pos, Vector2(pos.x + size.x, pos.y), Vector2(pos.x, pos.y + size.y), pos + size, p_color, viewport);
	}

	void fill_centred_rectangle(const Vector2 p_coord, const Vector2 p_size, const Color p_color, const Viewport* viewport)
	{
		fill_rectangle(p_coord - p_size / 2, p_size, p_color, viewport);
	}

	void draw_centred_rectangle(const Vector2 p_coord, const Vector2 p_size, const size_t width, const Color p_color, const Viewport* viewport)
	{
		draw_rectangle(p_coord - p_size / 2, p_size, width, p_color, viewport);
	}
}