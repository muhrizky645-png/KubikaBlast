using System.Collections.Generic;
using UnityEngine;

namespace KubikaBlast
{
    /// <summary>
    /// Mesh kubus satuan bersudut membulat (rounded cube) ala Block Blast.
    /// Diport dari Tetris3D.RoundedBlock.cs (Kubika Tower).
    /// Sisi datar tetap datar; tepi & sudut dibulatkan mulus.
    /// </summary>
    public static class RoundedCube
    {
        static Mesh _cached;

        /// <summary>Mesh kubus satuan (size 1) — dibuat sekali, dipakai bersama.</summary>
        public static Mesh Shared()
        {
            if (_cached == null) _cached = Build(0.5f, 0.15f, 6);
            return _cached;
        }

        // half   = setengah ukuran kubus (0.5 = kubus satuan)
        // radius = jari-jari lengkung sudut/tepi (0..half)
        // seg    = subdivisi per sisi (makin besar makin halus)
        public static Mesh Build(float half, float radius, int seg)
        {
            radius = Mathf.Clamp(radius, 0.001f, half);
            if (seg < 1) seg = 1;
            float inner = half - radius;

            var verts = new List<Vector3>();
            var norms = new List<Vector3>();
            var tris  = new List<int>();

            Vector3[] faceN = { Vector3.right, Vector3.left, Vector3.up, Vector3.down, Vector3.forward, Vector3.back };
            Vector3[] faceU = { Vector3.forward, Vector3.back, Vector3.right, Vector3.right, Vector3.left, Vector3.right };
            Vector3[] faceV = { Vector3.up, Vector3.up, Vector3.forward, Vector3.back, Vector3.up, Vector3.up };

            for (int f = 0; f < 6; f++)
            {
                Vector3 n = faceN[f];
                Vector3 u = faceU[f];
                Vector3 v = faceV[f];
                int baseIdx = verts.Count;
                int row = seg + 1;

                for (int iy = 0; iy <= seg; iy++)
                {
                    float ty = (float)iy / seg * 2f - 1f;
                    for (int ix = 0; ix <= seg; ix++)
                    {
                        float tx = (float)ix / seg * 2f - 1f;
                        Vector3 p = n * half + u * (tx * half) + v * (ty * half);
                        Vector3 clamped = new Vector3(
                            Mathf.Clamp(p.x, -inner, inner),
                            Mathf.Clamp(p.y, -inner, inner),
                            Mathf.Clamp(p.z, -inner, inner));
                        Vector3 dir = p - clamped;
                        Vector3 nrm = (dir.sqrMagnitude > 1e-6f) ? dir.normalized : n;
                        verts.Add(clamped + nrm * radius);
                        norms.Add(nrm);
                    }
                }

                for (int iy = 0; iy < seg; iy++)
                    for (int ix = 0; ix < seg; ix++)
                    {
                        int a = baseIdx + iy * row + ix;
                        int b = a + 1;
                        int c = a + row;
                        int d = c + 1;
                        tris.Add(a); tris.Add(c); tris.Add(b);
                        tris.Add(b); tris.Add(c); tris.Add(d);
                    }
            }

            var m = new Mesh { name = "KubikaRoundedCube" };
            m.indexFormat = (verts.Count > 65000)
                ? UnityEngine.Rendering.IndexFormat.UInt32
                : UnityEngine.Rendering.IndexFormat.UInt16;
            m.SetVertices(verts);
            m.SetNormals(norms);
            m.SetTriangles(tris, 0);
            m.RecalculateBounds();
            m.RecalculateTangents();
            return m;
        }
    }
}