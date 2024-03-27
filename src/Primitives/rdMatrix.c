#include "rdMatrix.h"

#include "../General/stdMath.h"
#include "globals.h"

#include <macros.h>

// 0x0042fb10
void rdMatrix_SetColumn(rdMatrix44* mat, int n, rdVector3* in)
{
    rdVector4* tmp = &mat->vA + n;
    tmp->x = in->x;
    tmp->y = in->y;
    tmp->z = in->z;
}

// 0x0042fb40
void rdMatrix_GetColumn(rdMatrix44* mat, int n, rdVector3* out)
{
    rdVector4* tmp = &mat->vA + n;
    out->x = tmp->x;
    out->y = tmp->y;
    out->z = tmp->z;
}

// 0x0042fb70
void rdMatrix_Multiply44(rdMatrix44* out, rdMatrix44* mat1, rdMatrix44* mat2)
{
    out->vA.x = mat2->vA.y * mat1->vB.x + mat1->vD.x * mat2->vA.w + mat1->vC.x * mat2->vA.z + mat2->vA.x * mat1->vA.x;
    out->vA.y = mat1->vA.y * mat2->vA.x + mat1->vC.y * mat2->vA.z + mat1->vD.y * mat2->vA.w + mat1->vB.y * mat2->vA.y;
    out->vA.z = mat1->vA.z * mat2->vA.x + mat1->vC.z * mat2->vA.z + mat1->vD.z * mat2->vA.w + mat1->vB.z * mat2->vA.y;
    out->vA.w = mat1->vA.w * mat2->vA.x + mat1->vC.w * mat2->vA.z + mat1->vD.w * mat2->vA.w + mat1->vB.w * mat2->vA.y;
    out->vB.x = mat2->vB.x * mat1->vA.x + mat2->vB.w * mat1->vD.x + mat2->vB.y * mat1->vB.x + mat2->vB.z * mat1->vC.x;
    out->vB.y = mat2->vB.x * mat1->vA.y + mat2->vB.z * mat1->vC.y + mat2->vB.w * mat1->vD.y + mat2->vB.y * mat1->vB.y;
    out->vB.z = mat2->vB.x * mat1->vA.z + mat2->vB.z * mat1->vC.z + mat2->vB.w * mat1->vD.z + mat2->vB.y * mat1->vB.z;
    out->vB.w = mat2->vB.x * mat1->vA.w + mat2->vB.w * mat1->vD.w + mat2->vB.z * mat1->vC.w + mat2->vB.y * mat1->vB.w;
    out->vC.x = mat2->vC.x * mat1->vA.x + mat2->vC.z * mat1->vC.x + mat2->vC.y * mat1->vB.x + mat2->vC.w * mat1->vD.x;
    out->vC.y = mat2->vC.x * mat1->vA.y + mat2->vC.y * mat1->vB.y + mat2->vC.w * mat1->vD.y + mat2->vC.z * mat1->vC.y;
    out->vC.z = mat2->vC.x * mat1->vA.z + mat2->vC.y * mat1->vB.z + mat2->vC.z * mat1->vC.z + mat2->vC.w * mat1->vD.z;
    out->vC.w = mat2->vC.x * mat1->vA.w + mat2->vC.y * mat1->vB.w + mat2->vC.w * mat1->vD.w + mat2->vC.z * mat1->vC.w;
    out->vD.x = mat2->vD.x * mat1->vA.x + mat2->vD.z * mat1->vC.x + mat2->vD.y * mat1->vB.x + mat2->vD.w * mat1->vD.x;
    out->vD.y = mat2->vD.w * mat1->vD.y + mat2->vD.y * mat1->vB.y + mat2->vD.x * mat1->vA.y + mat2->vD.z * mat1->vC.y;
    out->vD.z = mat2->vD.z * mat1->vC.z + mat2->vD.y * mat1->vB.z + mat2->vD.w * mat1->vD.z + mat2->vD.x * mat1->vA.z;
    out->vD.w = mat2->vD.w * mat1->vD.w + mat2->vD.y * mat1->vB.w + mat2->vD.x * mat1->vA.w + mat2->vD.z * mat1->vC.w;
}

// 0x0042ff80
void rdMatrix_Multiply44Acc(rdMatrix44* out, rdMatrix44* mat2)
{
    rdMatrix44 mat1;
    memcpy(&mat1, out, sizeof(rdMatrix44));

    out->vA.x = mat2->vA.y * mat1.vB.x + mat1.vD.x * mat2->vA.w + mat1.vC.x * mat2->vA.z + mat2->vA.x * mat1.vA.x;
    out->vA.y = mat1.vA.y * mat2->vA.x + mat1.vC.y * mat2->vA.z + mat1.vD.y * mat2->vA.w + mat1.vB.y * mat2->vA.y;
    out->vA.z = mat1.vA.z * mat2->vA.x + mat1.vC.z * mat2->vA.z + mat1.vD.z * mat2->vA.w + mat1.vB.z * mat2->vA.y;
    out->vA.w = mat1.vA.w * mat2->vA.x + mat1.vC.w * mat2->vA.z + mat1.vD.w * mat2->vA.w + mat1.vB.w * mat2->vA.y;
    out->vB.x = mat2->vB.x * mat1.vA.x + mat2->vB.w * mat1.vD.x + mat2->vB.y * mat1.vB.x + mat2->vB.z * mat1.vC.x;
    out->vB.y = mat2->vB.x * mat1.vA.y + mat2->vB.z * mat1.vC.y + mat2->vB.w * mat1.vD.y + mat2->vB.y * mat1.vB.y;
    out->vB.z = mat2->vB.x * mat1.vA.z + mat2->vB.z * mat1.vC.z + mat2->vB.w * mat1.vD.z + mat2->vB.y * mat1.vB.z;
    out->vB.w = mat2->vB.x * mat1.vA.w + mat2->vB.w * mat1.vD.w + mat2->vB.z * mat1.vC.w + mat2->vB.y * mat1.vB.w;
    out->vC.x = mat2->vC.x * mat1.vA.x + mat2->vC.z * mat1.vC.x + mat2->vC.y * mat1.vB.x + mat2->vC.w * mat1.vD.x;
    out->vC.y = mat2->vC.x * mat1.vA.y + mat2->vC.y * mat1.vB.y + mat2->vC.w * mat1.vD.y + mat2->vC.z * mat1.vC.y;
    out->vC.z = mat2->vC.x * mat1.vA.z + mat2->vC.y * mat1.vB.z + mat2->vC.z * mat1.vC.z + mat2->vC.w * mat1.vD.z;
    out->vC.w = mat2->vC.x * mat1.vA.w + mat2->vC.y * mat1.vB.w + mat2->vC.w * mat1.vD.w + mat2->vC.z * mat1.vC.w;
    out->vD.x = mat2->vD.x * mat1.vA.x + mat2->vD.z * mat1.vC.x + mat2->vD.y * mat1.vB.x + mat2->vD.w * mat1.vD.x;
    out->vD.y = mat2->vD.w * mat1.vD.y + mat2->vD.y * mat1.vB.y + mat2->vD.x * mat1.vA.y + mat2->vD.z * mat1.vC.y;
    out->vD.z = mat2->vD.z * mat1.vC.z + mat2->vD.y * mat1.vB.z + mat2->vD.w * mat1.vD.z + mat2->vD.x * mat1.vA.z;
    out->vD.w = mat2->vD.w * mat1.vD.w + mat2->vD.y * mat1.vB.w + mat2->vD.x * mat1.vA.w + mat2->vD.z * mat1.vC.w;
}

// 0x00430310
void rdMatrix_Unk1(rdMatrix44* m1, rdMatrix44* m2)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;

    fVar3 = (m2->vB).y;
    fVar4 = (m2->vB).x;
    fVar1 = (m2->vB).z;
    fVar2 = (m2->vC).x;
    fVar7 = fVar1 * fVar1 + fVar3 * fVar3 + fVar4 * fVar4;
    fVar1 = (m2->vC).y;
    fVar4 = (m2->vA).y;
    fVar3 = (m2->vC).z;
    fVar5 = (m2->vA).z;
    fVar6 = (m2->vA).x;
    fVar2 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
    (m1->vA).y = (m2->vB).x / fVar7;
    (m1->vA).z = (m2->vC).x / fVar2;
    (m1->vB).z = (m2->vC).y / fVar2;
    fVar1 = fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4;
    (m1->vB).x = (m2->vA).y / fVar1;
    (m1->vC).x = (m2->vA).z / fVar1;
    (m1->vC).y = (m2->vB).z / fVar7;
    (m1->vA).x = (m2->vA).x / fVar1;
    (m1->vB).y = (m2->vB).y / fVar7;
    fVar1 = (m2->vC).z;
    (m1->vA).w = 0.0;
    (m1->vB).w = 0.0;
    (m1->vC).w = 0.0;
    (m1->vD).w = 1.0;
    (m1->vC).z = fVar1 / fVar2;

    fVar6 = (m2->vD).x;
    fVar1 = (m2->vD).z;
    fVar7 = (m2->vD).y;
    fVar2 = (m1->vC).y;
    fVar3 = (m1->vA).z;
    fVar4 = (m1->vB).z;
    fVar5 = (m1->vC).z;
    (m1->vD).x = -((m1->vA).x * fVar6 + fVar7 * (m1->vB).x + fVar1 * (m1->vC).x);
    (m1->vD).y = -(fVar7 * (m1->vB).y + fVar6 * (m1->vA).y + fVar1 * fVar2);
    (m1->vD).z = -(fVar1 * fVar5 + fVar7 * fVar4 + fVar6 * fVar3);
    return;
}

// 0x00480690
void rdMatrix_TransformPoint44(rdVector4* a1, const rdVector4* a2, const rdMatrix44* a3)

{
    a1->x = (a3->vA.x * a2->x) + (a3->vB.x * a2->y) + (a3->vC.x * a2->z) + a3->vD.x;
    a1->y = (a3->vA.y * a2->x) + (a3->vB.y * a2->y) + (a3->vC.y * a2->z) + a3->vD.y;
    a1->z = (a3->vA.z * a2->x) + (a3->vB.z * a2->y) + (a3->vC.z * a2->z) + a3->vD.z;
    a1->w = (a3->vA.w * a2->x) + (a3->vB.w * a2->y) + (a3->vC.w * a2->z) + a3->vD.w;
    return;
}

// 0x00480730
void rdMatrix_ToTransRotScale(const rdMatrix44* mat, rdVector3* translation, rdMatrix44* rotation, rdVector3* scale)

{
    float fVar1;
    float fVar2;

    fVar2 = rdVector_Len3((rdVector3*)&mat->vA);
    fVar1 = 1.0 / fVar2;
    scale->x = fVar2;
    (rotation->vA).x = (mat->vA).x * fVar1;
    (rotation->vA).y = (mat->vA).y * fVar1;
    fVar2 = (mat->vA).z;
    (rotation->vA).w = 0.0;
    (rotation->vA).z = fVar2 * fVar1;
    fVar2 = rdVector_Len3((rdVector3*)&mat->vB);
    fVar1 = 1.0 / fVar2;
    scale->y = fVar2;
    (rotation->vB).x = (mat->vB).x * fVar1;
    (rotation->vB).y = (mat->vB).y * fVar1;
    fVar2 = (mat->vB).z;
    (rotation->vB).w = 0.0;
    (rotation->vB).z = fVar2 * fVar1;
    fVar2 = rdVector_Len3((rdVector3*)&mat->vC);
    fVar1 = 1.0 / fVar2;
    scale->z = fVar2;
    (rotation->vC).x = (mat->vC).x * fVar1;
    (rotation->vC).y = (mat->vC).y * fVar1;
    fVar2 = (mat->vC).z;
    (rotation->vC).w = 0.0;
    (rotation->vC).z = fVar2 * fVar1;
    translation->x = (mat->vD).x;
    translation->y = (mat->vD).y;
    translation->z = (mat->vD).z;
    (rotation->vD).x = 0.0;
    (rotation->vD).y = 0.0;
    (rotation->vD).z = 0.0;
    (rotation->vD).w = 1.0;
    return;
}

// 0x00480850
void rdMatrix_FromTransRotScale(rdMatrix44* mat, const rdVector3* translation, const rdMatrix44* rotation, const rdVector3* scale)
{
   HANG("TODO");
}

// 0x00430980
void rdMatrix_Multiply3(rdVector3* out, rdVector3* in, rdMatrix44* mat)
{
    out->x = (mat->vA).x * in->x + (mat->vB).x * in->y + (mat->vC).x * in->z;
    out->y = (mat->vA).y * in->x + (mat->vB).y * in->y + (mat->vC).y * in->z;
    out->z = (mat->vA).z * in->x + (mat->vB).z * in->y + (mat->vC).z * in->z;
    return;
}

// 0x00430a00
void rdMatrix_Transform3(rdVector3* out, rdVector3* in, rdMatrix44* mat)

{
    out->x = (mat->vA).x * in->x + (mat->vB).x * in->y + (mat->vC).x * in->z + (mat->vD).x;
    out->y = (mat->vA).y * in->x + (mat->vB).y * in->y + (mat->vC).y * in->z + (mat->vD).y;
    out->z = (mat->vA).z * in->x + (mat->vB).z * in->y + (mat->vC).z * in->z + (mat->vD).z;
    return;
}

// 0x00430ab0
void rdMatrix_Multiply4(rdVector4* out, rdVector4* in, rdMatrix44* mat)
{
    out->x = (mat->vA).x * in->x + (mat->vB).x * in->y + (mat->vC).x * in->z + (mat->vD).x * in->w;
    out->y = (mat->vA).y * in->x + (mat->vB).y * in->y + (mat->vC).y * in->z + (mat->vD).y * in->w;
    out->z = (mat->vA).z * in->x + (mat->vB).z * in->y + (mat->vC).z * in->z + (mat->vD).z * in->w;
    out->w = (mat->vA).w * in->x + (mat->vB).w * in->y + (mat->vC).w * in->z + (mat->vD).w * in->w;
    return;
}

// 0x00430b80
void rdMatrix_ExtractTransform(rdMatrix44* mat, swrTranslationRotation* tr_rot)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    rdVector3 local_24;
    float local_18;
    float local_14;
    float local_10;
    rdVector3 local_c;

    (tr_rot->translation).x = (mat->vD).x;
    (tr_rot->translation).y = (mat->vD).y;
    (tr_rot->translation).z = (mat->vD).z;
    fVar5 = (mat->vB).x;
    fVar1 = (mat->vB).y;
    fVar2 = (mat->vB).z;
    local_18 = -(mat->vA).x;
    local_14 = -(mat->vA).y;
    local_10 = -(mat->vA).z;
    local_24.z = 0.0;
    local_24.x = fVar5;
    local_24.y = fVar1;
    fVar3 = rdVector_Len3(&local_24);
    if (0.001 <= fVar3)
    {
        if (local_24.y / fVar3 <= 1.0)
        {
            fVar4 = stdMath_ArcCos(local_24.y / fVar3);
            if (0.0 < fVar5)
            {
                fVar4 = -fVar4;
            }
        }
        else
        {
            fVar4 = 0.0;
        }
        tr_rot->yaw_roll_pitch.x = fVar4;
    }
    else
    {
        fVar4 = stdMath_ArcCos(-local_18);
        if (0.0 < local_14 == 0.0 < fVar2)
        {
            fVar4 = -fVar4;
        }
        tr_rot->yaw_roll_pitch.z = fVar4;
        tr_rot->yaw_roll_pitch.x = 0.0;
    }
    if (0.001 <= fVar3)
    {
        fVar5 = (local_24.z * fVar2 + local_24.y * fVar1 + local_24.x * fVar5) / fVar3;
        if (fVar5 < 1.0)
        {
            fVar5 = stdMath_ArcCos(fVar5);
            tr_rot->yaw_roll_pitch.y = fVar5;
        }
        else
        {
            tr_rot->yaw_roll_pitch.y = 0.0;
        }
    }
    else
    {
        tr_rot->yaw_roll_pitch.y = 90.0;
    }
    if (fVar2 < 0.0)
    {
        tr_rot->yaw_roll_pitch.y = -tr_rot->yaw_roll_pitch.y;
    }
    local_c.x = -local_24.y;
    local_c.y = local_24.x;
    local_c.z = 0.0;
    fVar5 = rdVector_Len3(&local_c);
    if (0.001 <= fVar3)
    {
        fVar5 = (local_c.z * local_10 + local_c.y * local_14 + local_c.x * local_18) / fVar5;
        if (fVar5 < 1.0)
        {
            if (-1.0 < fVar5)
            {
                fVar5 = stdMath_ArcCos(fVar5);
                tr_rot->yaw_roll_pitch.z = fVar5;
            }
            else
            {
                tr_rot->yaw_roll_pitch.z = 180.0;
            }
        }
        else
        {
            tr_rot->yaw_roll_pitch.z = 0.0;
        }
        if (local_10 < 0.0)
        {
            tr_rot->yaw_roll_pitch.z = -tr_rot->yaw_roll_pitch.z;
            return;
        }
    }
    return;
}

/*
Z X Y
gamma alpha beta

{{cos(gamma),-sin(gamma),0},{sin(gamma),cos(gamma),0},{0,0,1}}
{{1,0,0},{0,cos(alpha),-sin(alpha)},{0,sin(alpha),cos(alpha)}}
{{cos(beta),0,sin(beta)},{0,1,0},{-sin(beta),0,cos(beta)}}
*/

// 0x00430e00
void rdMatrix_BuildRotation44(rdMatrix44* out, float gamma, float alpha, float beta)

{
    float sin_alpha;
    float cos_alpha;
    float sin_beta;
    float cos_beta;
    float sin_gamma;
    float cos_gamma;

    stdMath_SinCos(gamma, &sin_gamma, &cos_gamma);
    stdMath_SinCos(alpha, &sin_alpha, &cos_alpha);
    stdMath_SinCos(beta, &sin_beta, &cos_beta);
    (out->vA).x = cos_beta * cos_gamma - sin_beta * sin_gamma * sin_alpha;
    (out->vA).y = sin_beta * cos_gamma * sin_alpha + cos_beta * sin_gamma;
    (out->vA).z = -(sin_beta * cos_alpha);
    (out->vB).x = -(cos_alpha * sin_gamma);
    (out->vB).y = cos_alpha * cos_gamma;
    (out->vB).z = sin_alpha;
    (out->vC).x = cos_beta * sin_gamma * sin_alpha + sin_beta * cos_gamma;
    (out->vC).y = sin_beta * sin_gamma - cos_beta * cos_gamma * sin_alpha;
    (out->vC).z = cos_beta * cos_alpha;
    return;
}

// 0x00430f10
void rdMatrix_BuildRotation33(rdMatrix33* out, float gamma, float alpha, float beta)

{
    float cos_alpha;
    float sin_beta;
    float cos_beta;
    float sin_gamma;
    float cos_gamma;

    stdMath_SinCos(gamma, &sin_gamma, &cos_gamma);
    stdMath_SinCos(alpha, &gamma, &cos_alpha);
    stdMath_SinCos(beta, &sin_beta, &cos_beta);
    (out->rvec).x = cos_beta * cos_gamma - sin_beta * sin_gamma * gamma;
    (out->rvec).y = sin_beta * cos_gamma * gamma + cos_beta * sin_gamma;
    (out->rvec).z = -(sin_beta * cos_alpha);
    (out->lvec).x = -(cos_alpha * sin_gamma);
    (out->lvec).y = cos_alpha * cos_gamma;
    (out->lvec).z = gamma;
    (out->uvec).x = cos_beta * sin_gamma * gamma + sin_beta * cos_gamma;
    (out->uvec).y = sin_beta * sin_gamma - cos_beta * cos_gamma * gamma;
    (out->uvec).z = cos_beta * cos_alpha;
    return;
}

// 0x00431020
void rdMatrix_SetRotation44(rdMatrix44* out, float gamma, float alpha, float beta)

{
    (out->vD).x = 0.0;
    (out->vD).y = 0.0;
    (out->vD).z = 0.0;
    (out->vA).w = 0.0;
    (out->vB).w = 0.0;
    (out->vC).w = 0.0;
    (out->vD).w = 1.0;
    rdMatrix_BuildRotation44(out, gamma, alpha, beta);
    return;
}

// 0x00431060
void rdMatrix_SetTransform44(rdMatrix44* mat, swrTranslationRotation* v)
{
    (mat->vD).x = (v->translation).x;
    (mat->vD).y = (v->translation).y;
    (mat->vD).z = (v->translation).z;
    (mat->vA).w = 0.0;
    (mat->vB).w = 0.0;
    (mat->vC).w = 0.0;
    (mat->vD).w = 1.0;
    rdMatrix_BuildRotation44(mat, v->yaw_roll_pitch.x, v->yaw_roll_pitch.y, v->yaw_roll_pitch.z);
    return;
}

// 0x004310b0
void rdMatrix_SetDiagonal44(rdMatrix44* mat, float x, float y, float z)

{
    (mat->vA).x = x;
    (mat->vB).y = y;
    (mat->vC).z = z;
    (mat->vA).y = 0.0;
    (mat->vA).z = 0.0;
    (mat->vA).w = 0.0;
    (mat->vB).x = 0.0;
    (mat->vB).z = 0.0;
    (mat->vB).w = 0.0;
    (mat->vC).x = 0.0;
    (mat->vC).y = 0.0;
    (mat->vC).w = 0.0;
    (mat->vD).x = 0.0;
    (mat->vD).y = 0.0;
    (mat->vD).z = 0.0;
    (mat->vD).w = 1.0;
    return;
}

// 0x00431100
void rdMatrix_SetTranslation44(rdMatrix44* mat, float x, float y, float z)
{
    (mat->vA).y = 0.0;
    (mat->vA).z = 0.0;
    (mat->vA).w = 0.0;
    (mat->vB).x = 0.0;
    (mat->vB).z = 0.0;
    (mat->vB).w = 0.0;
    (mat->vC).x = 0.0;
    (mat->vC).y = 0.0;
    (mat->vC).w = 0.0;
    (mat->vD).x = x;
    (mat->vD).y = y;
    (mat->vD).z = z;
    (mat->vA).x = 1.0;
    (mat->vB).y = 1.0;
    (mat->vC).z = 1.0;
    (mat->vD).w = 1.0;
    return;
}

// 0x00431150
void rdMatrix_BuildFromVectorAngle44(rdMatrix44* mat, float angle, float x, float y, float z)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float angleRad_cos;
    float angleRad_sin[8]; // 8 items is a compilation artifact ?

    stdMath_SinCos(angle, angleRad_sin, &angleRad_cos);
    if (z < 0.999)
    {
        if (-0.999 < z)
        {
            fVar4 = x * x;
            fVar1 = y * y;
            fVar2 = fVar1 * angleRad_cos;
            fVar5 = (1.0 - fVar4) - fVar1;
            fVar3 = fVar4 * angleRad_cos;
            fVar6 = 1.0 - angleRad_cos;
            (mat->vA).x = (fVar3 * fVar5 + fVar2) / (1.0 - fVar5) + fVar4;
            fVar4 = y * x * fVar6;
            (mat->vB).y = (fVar2 * fVar5 + fVar3) / (1.0 - fVar5) + fVar1;
            fVar1 = z * x * fVar6;
            fVar6 = z * y * fVar6;
            (mat->vC).z = fVar3 + fVar2 + fVar5;
            (mat->vA).y = angleRad_sin[0] * z + fVar4;
            (mat->vB).x = fVar4 - angleRad_sin[0] * z;
            (mat->vA).z = fVar1 - angleRad_sin[0] * y;
            (mat->vC).x = angleRad_sin[0] * y + fVar1;
            (mat->vB).z = angleRad_sin[0] * x + fVar6;
            (mat->vC).y = fVar6 - angleRad_sin[0] * x;
        }
        else
        {
            (mat->vA).x = angleRad_cos;
            (mat->vB).y = angleRad_cos;
            (mat->vA).y = -angleRad_sin[0];
            (mat->vB).x = angleRad_sin[0];
            (mat->vA).z = 0.0;
            (mat->vB).z = 0.0;
            (mat->vC).x = 0.0;
            (mat->vC).y = 0.0;
            (mat->vC).z = 1.0;
        }
    }
    else
    {
        (mat->vA).x = angleRad_cos;
        (mat->vB).y = angleRad_cos;
        (mat->vB).x = -angleRad_sin[0];
        (mat->vA).y = angleRad_sin[0];
        (mat->vA).z = 0.0;
        (mat->vB).z = 0.0;
        (mat->vC).x = 0.0;
        (mat->vC).y = 0.0;
        (mat->vC).z = 1.0;
    }
    (mat->vD).x = 0.0;
    (mat->vD).y = 0.0;
    (mat->vD).z = 0.0;
    (mat->vA).w = 0.0;
    (mat->vB).w = 0.0;
    (mat->vC).w = 0.0;
    (mat->vD).w = 1.0;
    return;
}

// 0x00431390
void rdMatrix_AddRotationFromVectorAngle44Before(rdMatrix44* mat_out, float angle, float x, float y, float z, rdMatrix44* mat_in)
{
    rdMatrix44 tmp;

    rdMatrix_BuildFromVectorAngle44(&tmp, angle, x, y, z);
    rdMatrix_Multiply44(mat_out, &tmp, mat_in);
    return;
}

// 0x004313d0
void rdMatrix_SetIdentity44(rdMatrix44* mat)

{
    (mat->vA).x = 1.0;
    (mat->vA).y = 0.0;
    (mat->vA).z = 0.0;
    (mat->vA).w = 0.0;
    (mat->vB).x = 0.0;
    (mat->vB).y = 1.0;
    (mat->vB).z = 0.0;
    (mat->vB).w = 0.0;
    (mat->vC).x = 0.0;
    (mat->vC).y = 0.0;
    (mat->vC).z = 1.0;
    (mat->vC).w = 0.0;
    (mat->vD).x = 0.0;
    (mat->vD).y = 0.0;
    (mat->vD).z = 0.0;
    (mat->vD).w = 1.0;
    return;
}

// 0x00431410
void rdMatrix_AddRotationFromVectorAngle44After(rdMatrix44* mat_out, rdMatrix44* mat_in, float angle, float x, float y, float z)
{
    rdMatrix44 tmp;

    rdMatrix_BuildFromVectorAngle44(&tmp, angle, x, y, z);
    rdMatrix_Multiply44(mat_out, mat_in, &tmp);
    return;
}

// 0x00431450
void rdMatrix_ScaleBasis44(rdMatrix44* out, float scale_right, float scale_forward, float scale_up, rdMatrix44* in)
{
    (out->vA).x = scale_right * (in->vA).x;
    (out->vA).y = (in->vA).y * scale_right;
    (out->vA).z = (in->vA).z * scale_right;
    (out->vA).w = (in->vA).w * scale_right;
    (out->vB).x = (in->vB).x * scale_forward;
    (out->vB).y = (in->vB).y * scale_forward;
    (out->vB).z = (in->vB).z * scale_forward;
    (out->vB).w = (in->vB).w * scale_forward;
    (out->vC).x = (in->vC).x * scale_up;
    (out->vC).y = (in->vC).y * scale_up;
    (out->vC).z = (in->vC).z * scale_up;
    (out->vC).w = (in->vC).w * scale_up;
    (out->vD).x = (in->vD).x;
    (out->vD).y = (in->vD).y;
    (out->vD).z = (in->vD).z;
    (out->vD).w = (in->vD).w;
    return;
}

// 0x0044bad0
void rdMatrix_Copy44_34(rdMatrix44* dest, const rdMatrix34* src)
{
    rdMatrix44* cols_dest;
    rdMatrix44* rows_dest;
    int j;
    int i;
    rdVector3* cols_src;

    i = 4;
    rows_dest = dest;
    do
    {
        j = 3;
        cols_dest = rows_dest;
        do
        {
            cols_src = &src->rvec;
            src = (rdMatrix34*)&(src->rvec).y;
            (cols_dest->vA).x = cols_src->x;
            cols_dest = (rdMatrix44*)&(cols_dest->vA).y;
            j = j + -1;
        } while (j != 0);
        (rows_dest->vA).w = 0.0;
        rows_dest = (rdMatrix44*)&rows_dest->vB;
        i = i + -1;
    } while (i != 0);
    (dest->vD).w = 1.0;
    return;
}

// 0x0044bb10
void rdMatrix_Copy44(rdMatrix44* out, rdMatrix44* in)
{
    int c = 0;
    for (int i = 4; i > 0; i--)
    {
        for (int j = 4; j > 0; j--)
        {
            out[c] = in[c];
            c = c + 1;
        }
    }
}

// 0x00483690
void rdMatrix_BuildViewMatrix(rdMatrix44* viewMatrix_out, rdMatrix44* world)
{
    float vAx;
    float vAz;
    float vBz;
    float vCx;
    float vCz;

    (viewMatrix_out->vA).x = (world->vA).x;
    (viewMatrix_out->vB).x = (world->vA).y;
    (viewMatrix_out->vC).x = (world->vA).z;
    (viewMatrix_out->vA).z = -(world->vB).x;
    (viewMatrix_out->vB).z = -(world->vB).y;
    (viewMatrix_out->vC).z = -(world->vB).z;
    vCx = (viewMatrix_out->vC).x;
    vAx = (viewMatrix_out->vA).x;
    (viewMatrix_out->vA).y = (world->vC).x;
    (viewMatrix_out->vB).y = (world->vC).y;
    (viewMatrix_out->vC).y = (world->vC).z;
    vBz = (viewMatrix_out->vB).z;
    vCz = (viewMatrix_out->vC).z;
    vAz = (viewMatrix_out->vA).z;
    (viewMatrix_out->vD).x = -((viewMatrix_out->vB).x * (world->vD).y + vCx * (world->vD).z + vAx * (world->vD).x);
    (viewMatrix_out->vD).y = -((world->vD).y * (viewMatrix_out->vB).y + (world->vD).z * (viewMatrix_out->vC).y + (world->vD).x * (viewMatrix_out->vA).y);
    (viewMatrix_out->vD).z = -(vAz * (world->vD).x + vCz * (world->vD).z + vBz * (world->vD).y);
    (viewMatrix_out->vA).w = (world->vA).w;
    (viewMatrix_out->vB).w = (world->vB).w;
    (viewMatrix_out->vC).w = (world->vC).w;
    (viewMatrix_out->vD).w = (world->vD).w;
}

// 0x004924b0
void rdMatrix_BuildRotation34(rdMatrix34* out, rdVector3* angles, rdVector3* translation)
{
    float sin_alpha;
    float cos_alpha;
    float sin_beta;
    float sin_gamma;
    float cos_gamma;
    rdVector3 cos_beta;
    rdVector3* angles_;

    sin_alpha;
    stdMath_SinCosFast(angles->x, &sin_alpha, &cos_alpha);
    stdMath_SinCosFast(angles->y, &sin_gamma, &cos_gamma);
    stdMath_SinCosFast(angles->z, &sin_beta, &cos_beta.x);
    (out->rvec).x = -(sin_beta * sin_gamma) * sin_alpha + cos_beta.x * cos_gamma;
    (out->rvec).y = sin_beta * cos_gamma * sin_alpha + cos_beta.x * sin_gamma;
    (out->rvec).z = -sin_beta * cos_alpha;
    (out->lvec).x = -sin_gamma * cos_alpha;
    (out->lvec).y = cos_gamma * cos_alpha;
    (out->lvec).z = sin_alpha;
    (out->uvec).x = cos_beta.x * sin_gamma * sin_alpha + sin_beta * cos_gamma;
    (out->uvec).y = -sin_alpha * cos_beta.x * cos_gamma + sin_beta * sin_gamma;
    (out->uvec).z = cos_beta.x * cos_alpha;
    (out->scale).x = translation->x;
    (out->scale).y = translation->y;
    (out->scale).z = translation->z;
}

// 0x004925d0, World to Camera matrix
void rdMatrix_InvertOrtho34(rdMatrix34* out, rdMatrix34* in)
{
    float scalex;
    float scaley;
    float scalez;

    (out->rvec).y = (in->lvec).x;
    (out->rvec).z = (in->uvec).x;
    (out->lvec).z = (in->uvec).y;
    (out->lvec).x = (in->rvec).y;
    (out->uvec).x = (in->rvec).z;
    (out->uvec).y = (in->lvec).z;
    (out->rvec).x = (in->rvec).x;
    (out->lvec).y = (in->lvec).y;
    (out->uvec).z = (in->uvec).z;

    scaley = (in->scale).y;
    scalez = (in->scale).z;
    scalex = (in->scale).x;

    (out->scale).x = -(scalex * (in->rvec).x + (in->rvec).z * scalez + (in->rvec).y * scaley);
    (out->scale).y = -((in->lvec).z * scalez + (in->lvec).x * scalex + (in->lvec).y * scaley);
    (out->scale).z = -((in->uvec).x * scalex + (in->uvec).y * scaley + (in->uvec).z * scalez);
}

// 0x00492680, World to Camera matrix
void rdMatrix_InvertOrthoNorm34(rdMatrix34* out, rdMatrix34* in)
{
    float lvec_normsquare;
    float uvec_normsquare;
    float rvec_normsquare;

    rvec_normsquare = (in->rvec).x * (in->rvec).x + (in->rvec).z * (in->rvec).z + (in->rvec).y * (in->rvec).y;
    lvec_normsquare = (in->lvec).z * (in->lvec).z + (in->lvec).y * (in->lvec).y + (in->lvec).x * (in->lvec).x;
    uvec_normsquare = (in->uvec).z * (in->uvec).z + (in->uvec).y * (in->uvec).y + (in->uvec).x * (in->uvec).x;

    (out->rvec).x = (in->rvec).x / rvec_normsquare;
    (out->rvec).y = (in->lvec).x / lvec_normsquare;
    (out->rvec).z = (in->uvec).x / uvec_normsquare;

    (out->lvec).x = (in->rvec).y / rvec_normsquare;
    (out->lvec).y = (in->lvec).y / lvec_normsquare;
    (out->lvec).z = (in->uvec).y / uvec_normsquare;

    (out->uvec).x = (in->rvec).z / rvec_normsquare;
    (out->uvec).y = (in->lvec).z / lvec_normsquare;
    (out->uvec).z = (in->uvec).z / uvec_normsquare;

    (out->scale).x = -((in->scale).x * (out->rvec).x + (in->scale).y * (out->lvec).x + (in->scale).z * (out->uvec).x);
    (out->scale).y = -((in->scale).x * (out->rvec).y + (in->scale).y * (out->lvec).y + (in->scale).z * (out->uvec).y);
    (out->scale).z = -((in->scale).x * (out->rvec).z + (in->scale).y * (out->lvec).z + (in->scale).z * (out->uvec).z);
}

// 0x00492810
void rdMatrix_BuildRotate34(rdMatrix34* out, rdVector3* rot)
{
    float x_rad_sin, x_rad_cos;
    float y_rad_sin, y_rad_cos;
    float z_rad_sin, z_rad_cos;
    rdVector3* scale;

    scale = &out->scale;

    stdMath_SinCos(rot->x, &x_rad_sin, &x_rad_cos);
    stdMath_SinCos(rot->y, &y_rad_sin, &y_rad_cos);
    stdMath_SinCos(rot->z, &z_rad_sin, &z_rad_cos);
    out->rvec.x = -(z_rad_sin * y_rad_sin) * x_rad_sin + (z_rad_cos * y_rad_cos);
    out->rvec.y = ((z_rad_sin * y_rad_cos) * x_rad_sin) + (z_rad_cos * y_rad_sin);
    out->rvec.z = -z_rad_sin * x_rad_cos;
    out->lvec.x = -y_rad_sin * x_rad_cos;
    out->lvec.y = (y_rad_cos * x_rad_cos);
    out->lvec.z = x_rad_sin;
    out->uvec.x = ((z_rad_cos * y_rad_sin) * x_rad_sin) + (z_rad_sin * y_rad_cos);
    out->uvec.y = -x_rad_sin * (y_rad_cos * z_rad_cos) + (y_rad_sin * z_rad_sin);
    out->uvec.z = z_rad_cos * x_rad_cos;
    scale->x = 0.0;
    scale->y = 0.0;
    scale->z = 0.0;
}

// 0x00492930
void rdMatrix_BuildTranslate34(rdMatrix34* out, rdVector3* tV)
{
    memcpy(out, &rdMatrix34_identity, sizeof(rdMatrix34));
    rdVector_Copy3(&out->scale, tV);
}

// 0x00492960
void rdMatrix_ExtractAngles34(rdMatrix34* in, rdVector3* out)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;

    fVar4 = -(in->rvec).x;
    fVar9 = (in->lvec).x;
    fVar2 = (in->lvec).y;
    fVar5 = -(in->rvec).y;
    fVar1 = (in->rvec).z;
    fVar3 = (in->lvec).z;
    fVar8 = fVar2 * fVar2 + fVar9 * fVar9;
    fVar6 = stdMath_Sqrt(fVar8);
    if (0.001 <= fVar6)
    {
        fVar7 = stdMath_ArcSin3(fVar2 / fVar6);
        fVar7 = 90.0 - fVar7;
        if (0.0 < fVar9)
        {
            fVar7 = -fVar7;
        }
        out->y = fVar7;
    }
    else
    {
        fVar7 = stdMath_ArcSin3(-fVar4);
        fVar7 = 90.0 - fVar7;
        if (((0.0 < fVar5) && (0.0 < fVar3)) || ((fVar5 < 0.0 && (fVar3 < 0.0))))
        {
            fVar7 = -fVar7;
        }
        out->z = fVar7;
        out->y = 0.0;
    }
    if (0.001 <= fVar6)
    {
        fVar8 = fVar8 / fVar6;
        if (fVar8 < 1.0)
        {
            fVar8 = stdMath_ArcSin3(fVar8);
            out->x = 90.0 - fVar8;
        }
        else
        {
            out->x = 0.0;
        }
    }
    else
    {
        out->x = 90.0;
    }
    if (fVar3 < 0.0)
    {
        out->x = -out->x;
    }
    fVar2 = -fVar2;
    if (0.001 <= fVar6)
    {
        fVar9 = (fVar2 * fVar4 + fVar5 * fVar9) / stdMath_Sqrt(fVar2 * fVar2 + fVar9 * fVar9);
        if (fVar9 < 1.0)
        {
            if (-1.0 < fVar9)
            {
                fVar9 = stdMath_ArcSin3(fVar9);
                out->z = 90.0 - fVar9;
            }
            else
            {
                out->z = 180.0;
            }
        }
        else
        {
            out->z = 0.0;
        }
        if (-fVar1 < 0.0)
        {
            out->z = -out->z;
        }
    }
}

// 0x00492b70
void rdMatrix_Multiply34(rdMatrix34* out, rdMatrix34* mat1, rdMatrix34* mat2)
{
    (out->rvec).x = (mat1->uvec).x * (mat2->rvec).z + (mat1->lvec).x * (mat2->rvec).y + (mat2->rvec).x * (mat1->rvec).x;
    (out->rvec).y = (mat2->rvec).y * (mat1->lvec).y + (mat2->rvec).z * (mat1->uvec).y + (mat1->rvec).y * (mat2->rvec).x;
    (out->rvec).z = (mat2->rvec).y * (mat1->lvec).z + (mat2->rvec).z * (mat1->uvec).z + (mat1->rvec).z * (mat2->rvec).x;
    (out->lvec).x = (mat1->lvec).x * (mat2->lvec).y + (mat1->uvec).x * (mat2->lvec).z + (mat2->lvec).x * (mat1->rvec).x;
    (out->lvec).y = (mat1->rvec).y * (mat2->lvec).x + (mat1->uvec).y * (mat2->lvec).z + (mat1->lvec).y * (mat2->lvec).y;
    (out->lvec).z = (mat1->rvec).z * (mat2->lvec).x + (mat2->lvec).y * (mat1->lvec).z + (mat1->uvec).z * (mat2->lvec).z;
    (out->uvec).x = (mat1->uvec).x * (mat2->uvec).z + (mat1->lvec).x * (mat2->uvec).y + (mat2->uvec).x * (mat1->rvec).x;
    (out->uvec).y = (mat1->uvec).y * (mat2->uvec).z + (mat1->lvec).y * (mat2->uvec).y + (mat1->rvec).y * (mat2->uvec).x;
    (out->uvec).z = (mat1->lvec).z * (mat2->uvec).y + (mat1->rvec).z * (mat2->uvec).x + (mat1->uvec).z * (mat2->uvec).z;
    (out->scale).x = (mat1->uvec).x * (mat2->scale).z + (mat1->lvec).x * (mat2->scale).y + (mat2->scale).x * (mat1->rvec).x + (mat1->scale).x;
    (out->scale).y = (mat1->lvec).y * (mat2->scale).y + (mat1->uvec).y * (mat2->scale).z + (mat1->rvec).y * (mat2->scale).x + (mat1->scale).y;
    (out->scale).z = (mat1->uvec).z * (mat2->scale).z + (mat1->rvec).z * (mat2->scale).x + (mat1->lvec).z * (mat2->scale).y + (mat1->scale).z;
}

// 0x00492d50
void rdMatrix_PreMultiply34(rdMatrix34* mat1, rdMatrix34* mat2)
{
    rdMatrix34 tmp;
    memcpy(&tmp, mat1, sizeof(tmp));
    (mat1->rvec).x = tmp.rvec.x * (mat2->rvec).x + (mat2->rvec).z * tmp.uvec.x + (mat2->rvec).y * tmp.lvec.x;
    (mat1->rvec).y = tmp.rvec.y * (mat2->rvec).x + (mat2->rvec).z * tmp.uvec.y + (mat2->rvec).y * tmp.lvec.y;
    (mat1->rvec).z = tmp.rvec.z * (mat2->rvec).x + (mat2->rvec).z * tmp.uvec.z + (mat2->rvec).y * tmp.lvec.z;
    (mat1->lvec).x = (mat2->lvec).z * tmp.uvec.x + (mat2->lvec).x * tmp.rvec.x + (mat2->lvec).y * tmp.lvec.x;
    (mat1->lvec).y = (mat2->lvec).z * tmp.uvec.y + (mat2->lvec).x * tmp.rvec.y + (mat2->lvec).y * tmp.lvec.y;
    (mat1->lvec).z = (mat2->lvec).z * tmp.uvec.z + (mat2->lvec).x * tmp.rvec.z + (mat2->lvec).y * tmp.lvec.z;
    (mat1->uvec).x = (mat2->uvec).x * tmp.rvec.x + (mat2->uvec).y * tmp.lvec.x + (mat2->uvec).z * tmp.uvec.x;
    (mat1->uvec).y = (mat2->uvec).x * tmp.rvec.y + (mat2->uvec).y * tmp.lvec.y + (mat2->uvec).z * tmp.uvec.y;
    (mat1->uvec).z = (mat2->uvec).x * tmp.rvec.z + (mat2->uvec).y * tmp.lvec.z + (mat2->uvec).z * tmp.uvec.z;
    (mat1->scale).x = (mat2->scale).x * tmp.rvec.x + (mat2->scale).y * tmp.lvec.x + (mat2->scale).z * tmp.uvec.x + tmp.scale.x;
    (mat1->scale).y = (mat2->scale).x * tmp.rvec.y + (mat2->scale).y * tmp.lvec.y + (mat2->scale).z * tmp.uvec.y + tmp.scale.y;
    (mat1->scale).z = (mat2->scale).x * tmp.rvec.z + (mat2->scale).y * tmp.lvec.z + (mat2->scale).z * tmp.uvec.z + tmp.scale.z;
}

// 0x00492f40
void rdMatrix_PostMultiply34(rdMatrix34* mat1, rdMatrix34* mat2)
{
    rdMatrix34 tmp;
    memcpy(&tmp, mat1, sizeof(tmp));
    (mat1->rvec).x = tmp.rvec.x * (mat2->rvec).x + (mat2->lvec).x * tmp.rvec.y + (mat2->uvec).x * tmp.rvec.z;
    (mat1->rvec).y = (mat2->lvec).y * tmp.rvec.y + (mat2->uvec).y * tmp.rvec.z + (mat2->rvec).y * tmp.rvec.x;
    (mat1->rvec).z = (mat2->rvec).z * tmp.rvec.x + (mat2->uvec).z * tmp.rvec.z + (mat2->lvec).z * tmp.rvec.y;
    (mat1->lvec).x = tmp.lvec.x * (mat2->rvec).x + (mat2->lvec).x * tmp.lvec.y + (mat2->uvec).x * tmp.lvec.z;
    (mat1->lvec).y = (mat2->lvec).y * tmp.lvec.y + (mat2->uvec).y * tmp.lvec.z + (mat2->rvec).y * tmp.lvec.x;
    (mat1->lvec).z = (mat2->rvec).z * tmp.lvec.x + (mat2->uvec).z * tmp.lvec.z + (mat2->lvec).z * tmp.lvec.y;
    (mat1->uvec).x = tmp.uvec.x * (mat2->rvec).x + (mat2->lvec).x * tmp.uvec.y + (mat2->uvec).x * tmp.uvec.z;
    (mat1->uvec).y = (mat2->lvec).y * tmp.uvec.y + (mat2->uvec).y * tmp.uvec.z + (mat2->rvec).y * tmp.uvec.x;
    (mat1->uvec).z = (mat2->rvec).z * tmp.uvec.x + (mat2->uvec).z * tmp.uvec.z + (mat2->lvec).z * tmp.uvec.y;
    (mat1->scale).x = tmp.scale.x * (mat2->rvec).x + (mat2->lvec).x * tmp.scale.y + (mat2->uvec).x * tmp.scale.z + (mat2->scale).x;
    (mat1->scale).y = (mat2->lvec).y * tmp.scale.y + (mat2->uvec).y * tmp.scale.z + (mat2->rvec).y * tmp.scale.x + (mat2->scale).y;
    (mat1->scale).z = (mat2->rvec).z * tmp.scale.x + (mat2->uvec).z * tmp.scale.z + (mat2->lvec).z * tmp.scale.y + (mat2->scale).z;
}

// 0x00493130
void rdMatrix_PreRotate34(rdMatrix34* out, rdVector3* rot)
{
    rdMatrix34 tmp;
    rdMatrix_BuildRotate34(&tmp, rot);
    rdMatrix_PreMultiply34(out, &tmp);
}

// 0x00493160
void rdMatrix_PostTranslate34(rdMatrix34* mat, rdVector3* v)
{
    (mat->scale).x = v->x + (mat->scale).x;
    (mat->scale).y = v->y + (mat->scale).y;
    (mat->scale).z = v->z + (mat->scale).z;
}

// 0x00493190
void rdMatrix_TransformVector34(rdVector3* out, rdVector3* v, rdMatrix34* m)
{
    out->x = v->x * (m->rvec).x + v->y * (m->lvec).x + v->z * (m->uvec).x;
    out->y = (m->rvec).y * v->x + (m->uvec).y * v->z + v->y * (m->lvec).y;
    out->z = (m->rvec).z * v->x + (m->uvec).z * v->z + v->y * (m->lvec).z;
}

// 0x00493200
void rdMatrix_TransformPoint34(rdVector3* vOut, rdVector3* vIn, rdMatrix34* camera)
{
    vOut->x = vIn->x * (camera->rvec).x + vIn->z * (camera->uvec).x + vIn->y * (camera->lvec).x + (camera->scale).x;
    vOut->y = (camera->rvec).y * vIn->x + (camera->uvec).y * vIn->z + vIn->y * (camera->lvec).y + (camera->scale).y;
    vOut->z = (camera->rvec).z * vIn->x + (camera->uvec).z * vIn->z + vIn->y * (camera->lvec).z + (camera->scale).z;
}

// 0x00493270
void rdMatrix_TransformPointLst34(rdMatrix34* m, rdVector3* in, rdVector3* out, int num)
{
    if (num != 0)
    {
        do
        {
            out->x = in->x * (m->rvec).x + in->z * (m->uvec).x + in->y * (m->lvec).x + (m->scale).x;
            out->y = in->z * (m->uvec).y + in->y * (m->lvec).y + (m->rvec).y * in->x + (m->scale).y;
            out->z = in->z * (m->uvec).z + in->y * (m->lvec).z + (m->rvec).z * in->x + (m->scale).z;
            out = out + 1;
            num = num + -1;
            in = in + 1;
        } while (num != 0);
    }
}
