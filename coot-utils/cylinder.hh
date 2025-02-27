
#ifndef COOT_CYLINDER_HH
#define COOT_CYLINDER_HH

#include <vector>
#include "vertex.hh"
#include "coot-utils/g_triangle.hh"

class cylinder {
   void add_flat_cap(float z);
   float height;
   float base_radius;
   float top_radius;
   unsigned int n_slices;
   glm::mat4 ori;
   glm::vec3 start;
   glm::vec4 basic_colour;
   float unstubby_rounded_cap_factor;
   // add these new triangles to the mesh
   void add_vertices_and_triangles(const std::pair<std::vector<coot::api::vnc_vertex>, std::vector<g_triangle> > &vt);
   void init(const std::pair<glm::vec3, glm::vec3> &cart_pair,
             float base_radius, float top_radius, float height,
             const glm::vec4 &base_colour,
             unsigned int n_slices=8, unsigned int n_stacks=2);
   void add_flat_cap(int end_type); // 0 for base, 1 for top
public:
   std::vector<coot::api::vnc_vertex> vertices;
   std::vector<g_triangle> triangles;
   cylinder() {
      height = 1.0; base_radius = 1.0; top_radius = 1.0; n_slices = 16;
      unstubby_rounded_cap_factor = 1.0; } // needs to be filled
   cylinder(const std::pair<glm::vec3, glm::vec3> &pos_pair,
            float base_radius, float top_radius, float height,
            unsigned int n_slices=8, unsigned int n_stacks=2);
   cylinder(const std::pair<glm::vec3, glm::vec3> &pos_pair,
            float base_radius, float top_radius, float height,
            const glm::vec4 &base_colour,
            unsigned int n_slices=8, unsigned int n_stacks=2);
   void add_flat_end_cap();
   void add_flat_start_cap();
   void add_octahemisphere_end_cap();
   void add_octahemisphere_start_cap();
   void set_unstubby_rounded_cap_factor(float f) { unstubby_rounded_cap_factor = f; }
   void z_translate(float zt);
   void add_sad_face(); // to move the eyesballs. the eyes would have to be in a different mesh.
   void crenulations();
};

#endif
