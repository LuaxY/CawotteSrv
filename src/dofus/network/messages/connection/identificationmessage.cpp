//
// identificationmessage.cpp
// CawotteSrv
//
// Created by Luax on 7/4/15.
// Copyright (c) 2015 Luax. All rights reserved.
//

#include "identificationmessage.h"

void IdentificationMessage::initIdentificationMessage()
{

}

unsigned short IdentificationMessage::getId()
{
    return id;
}

std::string IdentificationMessage::getName()
{
    return "IdentificationMessage";
}
void IdentificationMessage::serialize(BinaryWriter& writer)
{
    char box0 = 0;
    BooleanByteWrapper::setFlag(box0, 0, autoConnect);
    BooleanByteWrapper::setFlag(box0, 1, useCertificate);
    BooleanByteWrapper::setFlag(box0, 2, useLoginToken);
    writer.writeByte(box0);
    version.serialize(writer);
    writer.writeUTF(lang);
    writer.writeUInt(credentials.size()); // TODO: implement writeVarInt
    writer.writeBytes(credentials, false);
    writer.writeShort(serverId);
    writer.writeLong(sessionOptionalSalt); // TODO: implement writeVarLong
    writer.writeShort(failedAttempts.size());
    for (int i = 0; i < failedAttempts.size(); ++i)
    {
        writer.writeUShort(failedAttempts[i]); // TODO: implement writeVarUhShort
    }
}

void IdentificationMessage::deserialize(BinaryReader& reader)
{
    char box0 = reader.readByte();
    autoConnect = BooleanByteWrapper::getFlag(box0, 0);
    useCertificate = BooleanByteWrapper::getFlag(box0, 1);
    useLoginToken = BooleanByteWrapper::getFlag(box0, 2);
    version.deserialize(reader);
    lang = reader.readUTF();
    unsigned int credentialsLen = reader.readUInt(); // TODO: implement readVarInt
    credentials = reader.readBytes(credentialsLen);
    serverId = reader.readShort();
    sessionOptionalSalt = reader.readLong(); // TODO: implement readVarLong
    unsigned int failedAttemptsLen = reader.readUShort();
    for (int i = 0; i < failedAttemptsLen; ++i)
    {
        unsigned short attempt = reader.readUShort(); // TODO: implement readVarUhShort
        failedAttempts.push_back(attempt);
    }
}