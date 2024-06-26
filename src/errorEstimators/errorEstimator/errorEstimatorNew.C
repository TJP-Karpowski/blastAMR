/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2019-2020
     \\/     M anipulation  | Synthetik Applied Technologies
-------------------------------------------------------------------------------
License
    This file is derivative work of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------*/

#include "errorEstimator.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::errorEstimator> Foam::errorEstimator::New
(
    const fvMesh& mesh,
    const dictionary& dict,
    const word& name
)
{
    const word errorEstimatorType(dict.lookup("errorEstimator"));

    Info<< "Selecting errorEstimator: " << errorEstimatorType << endl;

    auto* ctorPtr = dictionaryConstructorTable(errorEstimatorType);

    if (ctorPtr == nullptr)
    {
        FatalErrorInFunction
            << "Unknown errorEstimator type "
            << errorEstimatorType << endl << endl
            << "Valid errorEstimator types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return ctorPtr(mesh, dict, name);
}


// ************************************************************************* //
