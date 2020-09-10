#include "jgl.h"

namespace jgl
{
	void			draw_pixel_color(const Vector3 points, const Color colors, const size_t nb)
	{
		GLfloat* g_vertex_buffer_data = (float*)(&points);

		GLfloat* g_color_buffer_data = (float*)(&colors);

		glBindVertexArray(g_application->vertex_array());

		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 3, g_vertex_buffer_data);

		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 4, g_color_buffer_data);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glUseProgram(g_application->program_color());

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(nb));
	}

	void			draw_line_color(const Vector3* points, const Color* colors, const size_t nb)
	{
		GLfloat* g_vertex_buffer_data = (float*)(points);

		GLfloat* g_color_buffer_data = (float*)(colors);

		glBindVertexArray(g_application->vertex_array());

		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 3, g_vertex_buffer_data);

		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 4, g_color_buffer_data);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glUseProgram(g_application->program_color());

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(nb));
	}

	void			draw_triangle_color(const Vector3* points, const Color* colors, const size_t nb)
	{
		GLfloat* g_vertex_buffer_data = (float*)(points);

		GLfloat* g_color_buffer_data = (float*)(colors);

		glBindVertexArray(g_application->vertex_array());

		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 3, g_vertex_buffer_data);

		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 4, g_color_buffer_data);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glUseProgram(g_application->program_color());

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(nb));
	}

	void			fill_triangle_color(const Vector3* points, const Color* colors, const size_t nb)
	{
		GLfloat* g_vertex_buffer_data = (float*)(points);

		GLfloat* g_color_buffer_data = (float*)(colors);

		glBindVertexArray(g_application->vertex_array());

		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 3, g_vertex_buffer_data);

		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 4, g_color_buffer_data);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glUseProgram(g_application->program_color());

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->color_buffer());
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(nb));
	}

	void			draw_triangle_texture(const Vector3* points, const Vector2* uvs, const float alpha, const size_t nb)
	{
		GLfloat* g_vertex_buffer_data = (float*)(points);

		GLfloat* g_uv_buffer_data = (float*)(uvs);

		glBindVertexArray(g_application->vertex_array());

		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 3, g_vertex_buffer_data);

		glBindBuffer(GL_ARRAY_BUFFER, g_application->texture_buffer());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * nb * 2, g_uv_buffer_data);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glUseProgram(g_application->program_texture());

		glUniform1f(g_application->alphaID(), alpha);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->vertex_buffer());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, g_application->texture_buffer());
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(nb));
	}
}